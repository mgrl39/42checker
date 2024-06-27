# Descriptores de archivo (FD) | Guía
// https://42-cursus.gitbook.io/guide/useful-tools/file-descriptors-fd
🗃️ Descriptores de archivo (FD)

Intentaré explicar qué es un descriptor de archivo ya que se utiliza en la mayoría de los proyectos.

## ¿Qué es un Descriptor de Archivo?

Un descriptor de archivo es una variable de tipo `int` que identifica de manera única un archivo abierto.

### Terminología

Antes de continuar con la explicación, debo describir algunos términos que utilizaré en esta página.

| Término                | Descripción                                                                                                                                               |
|------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Descriptor de Archivo  | Este es el índice de la Entrada de la Tabla de Archivos en la tabla de descriptores de archivo.                                                            |
| Tabla de Descriptores  | Esta es una matriz de Entradas de la Tabla de Archivos, cada proceso tiene su propia Tabla de Descriptores de Archivos.                                   |
| Entrada de la Tabla    | Una Entrada de la Tabla de Archivos es una estructura que contiene información sobre un archivo.                                                           |
| Tabla Global de Archivos | Esta es una tabla a nivel del sistema que contiene todos los archivos. (No puede contener todos los archivos a la vez, pero el sistema operativo la actualizará automáticamente si solicita un archivo que no está en esta tabla). |

Cuando usas un descriptor de archivo, con la función `read(2)` por ejemplo, lo siguiente sucederá:

1. Buscar el archivo en la Tabla Global de Archivos:
    - Si el archivo se encuentra, ir al siguiente paso.
    - Si el archivo no se encuentra, el sistema operativo actualizará la Tabla Global de Archivos para hacer el archivo solicitado disponible, luego volverá al paso 1.
   
2. Crear una Entrada en la Tabla de Archivos en la Tabla de Descriptores de Archivos para el archivo solicitado.

3. Asignar el primer Descriptor de Archivo no usado a la entrada creada en la tabla de archivos.

// insertar esquema aquí

### Descriptores de archivo estándar

En C, como en la mayoría de los sistemas Unix, hay 3 descriptores de archivo estándar que se agregan automáticamente a la tabla de descriptores de archivo. Estos descriptores de archivo son los descriptores de entrada/salida estándar y siempre tienen estos valores:

- **0**: este descriptor de archivo representa el `stdin` (=> entrada estándar, la terminal). Este es el descriptor de archivo que se usa cuando se lee la entrada del usuario desde la terminal.
- **1**: este descriptor de archivo representa el `stdout` (=> salida estándar, la terminal). Este es el descriptor de archivo que se usa cuando se escribe en la terminal.
- **2**: este descriptor de archivo representa el `stderr` (=> salida de error estándar, la terminal). Este es el descriptor de archivo que se usa cuando se escribe un error en la terminal. La información se escribe de la misma manera, pero un programa que registra errores en un archivo puede redirigir todo lo escrito al descriptor de archivo `stderr` a un archivo. Es gestionado de otra manera por el sistema operativo.

### Ejemplos

Cuando usas la función `write(2)`, en realidad estás usando un descriptor de archivo.

El prototipo de la función `write(2)` es el siguiente:

```c
size_t write(int fd, const void *buf, size_t count);
```

Como puedes ver, el primer parámetro de esta función es un `int` llamado `fd`, ¿te suena familiar verdad?

Puedes especificar en qué archivo escribir con el primer parámetro. Haré un ejemplo rápido para mostrarte cómo podría usarse.

```c
// Incluyendo la cabecera unistd para la función write(2)
#include <unistd.h>
// Incluyendo la cabecera fcntl para la función open(2)
#include <fcntl.h>

// Prototipos de las funciones declaradas bajo la función main
void ft_putchar_terminal(char c);
void ft_putchar_test_file(char c);

// función main
int main(void)
{
    // llamando a la función ft_putchar_terminal con el carácter T
    ft_putchar_terminal("T");
    // llamando a la función ft_putchar_test_file con el carácter F
    ft_putchar_test_file("F");
    return (0);
}

/* Esta función simplemente escribirá un carácter en la terminal en la 
 * salida estándar. Como se explicó anteriormente, el fd para stdout es 1,
 * así que ponemos 1 como primer parámetro para la función write(2).
 */
void ft_putchar_terminal(char c)
{
    write(1, &c, 1);
}

/* Esta función abrirá un archivo llamado "test.txt" con la función open(2).
 * Una vez que el archivo esté abierto, almacenará el descriptor de archivo 
 * en la variable fd. Luego verifico si hubo un error al abrir el archivo.
 * Si no hay error, escribo el carácter F en el archivo test.txt
 * Si hay un error, escribo un mensaje de error en la salida de error estándar.
 */
void ft_putchar_test_file(char c)
{
    int fd;
    
    /* Abriendo el archivo test.txt en modo Lectura/Escritura con la función open(2)
     * luego asignando el valor de descriptor de archivo devuelto a la variable fd.
     */
    fd = open("test.txt", O_RDWR);
    /* Verificando si el archivo fue abierto correctamente.
     * La función open devuelve -1 si hay un error al abrir el archivo.
     */
    if (fd > 0)
        /* Escribiendo el carácter F en el archivo test.txt pasando
         * su descriptor de archivo como primer parámetro a la función write(2).
         */
        write(fd, &c, 1);
    else
        /* Si hubo un error al abrir el archivo, el valor de fd será -1
         * por lo tanto, no entrará en la condición anterior, así que escribo
         * un mensaje de error en stderr pasando el descriptor fd 2 como primer parámetro
         * a la función write(2).
         */
        write(2, "test.txt not found.\n", 20);
}
```

### Cómo funciona

Cuando lees bytes desde un descriptor de archivo, recuerda dónde en el archivo estuvo la última vez.

Esto significa que, si lees 20 bytes de un archivo, la próxima vez que leas desde el mismo descriptor de archivo, comenzará a leer desde el byte 21. Echa un vistazo al ejemplo a continuación.

```c
// Incluyendo la cabecera unistd para las funciones write(2) y read(2)
#include <unistd.h>
// Incluyendo la cabecera fcntl para la función open(2)
#include <fcntl.h>

// Prototipos de las funciones declaradas bajo la función main
void ft_putchar_terminal(char c);
void ft_putchar_test_file(char c);

// función main
int main(void)
{
    // llamando a la función ft_putchar_terminal con el carácter T
    ft_putchar_terminal("T");
    // llamando a la función ft_putchar_test_file con el carácter F
    ft_putchar_test_file("F");
    return (0);
}

/* Esta función simplemente escribirá un carácter en la terminal en la 
 * salida estándar. Como se explicó anteriormente, el fd para stdout es 1,
 * así que ponemos 1 como primer parámetro para la función write(2).
 */
void ft_putchar_terminal(char c)
{
    write(1, &c, 1);
}

/* Esta función abrirá un archivo llamado "test.txt" con la función open(2).
 * Una vez que el archivo esté abierto, almacenará el descriptor de archivo 
 * en la variable fd. Luego verifico si hubo un error al abrir el archivo.
 * Si no hay error, escribo el carácter F en el archivo test.txt
 * Si hay un error, escribo un mensaje de error en la salida de error estándar.
 */
void ft_putchar_test_file(char c)
{
    int fd;
    
    /* Abriendo el archivo test.txt en modo Lectura/Escritura con la función open(2)
     * luego asignando el valor de descriptor de archivo devuelto a la variable fd.
     */
    fd = open("test.txt", O_RDWR);
    /* Verificando si el archivo fue abierto correctamente.
     * La función open devuelve -1 si hay un error al abrir el archivo.
     */
    if (fd > 0)
        /* Escribiendo el carácter F en el archivo test.txt pasando
         * su descriptor de archivo como primer parámetro a la función write(2).
         */
        write(fd, &c, 1);
    else
        /* Si hubo un error al abrir el archivo, el valor de fd será -1
         * por lo tanto, no entrará en la condición anterior, así que escribo
         * un mensaje de error en stderr pasando el descriptor fd 2 como primer parámetro
         * a la función write(2).
         */
        write(2, "test.txt not found.\n", 20);
}
```
