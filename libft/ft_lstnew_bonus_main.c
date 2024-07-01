#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Definición de la estructura t_list
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

// Implementación de la función ft_lstnew
t_list *ft_lstnew(void *content);

// Función para imprimir un número
void ft_putnbr(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

// Función para imprimir una cadena
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

// Función para imprimir la lista
void print_list(t_list *lst)
{
    while (lst != NULL)
    {
        ft_putstr((char *)lst->content);
        if (lst->next != NULL)
            ft_putstr(" -> ");
        lst = lst->next;
    }
    ft_putstr("\n");
}

// Función principal para visualizar ft_lstnew
int main()
{
    // Crear varios nodos
    t_list *node1 = ft_lstnew("Nodo 1");
    t_list *node2 = ft_lstnew("Nodo 2");
    t_list *node3 = ft_lstnew("Nodo 3");

    // Enlazar los nodos
    node1->next = node2;
    node2->next = node3;

    // Verificar si los nodos fueron creados exitosamente
    if (node1 == NULL || node2 == NULL || node3 == NULL)
    {
        ft_putstr("Error al crear los nodos.\n");
        return (1);
    }

    // Imprimir el contenido de la lista
    print_list(node1);

    // Liberar la memoria de los nodos
    free(node1);
    free(node2);
    free(node3);

    return (0);
}
