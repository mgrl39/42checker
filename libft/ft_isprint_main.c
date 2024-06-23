#include <unistd.h>

// Prototipo de ft_isprint
int ft_isprint(int c);

// Prototipo de ft_putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Prototipo de ft_putstr 
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

// Definición de colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int main(void)
{
    int c;
    int result;

    ft_putstr("Testing ft_isprint function...\n");

    c = 0;
    while (c <= 127)
    {
        result = ft_isprint(c);
        if ((c >= 32 && c <= 126 && result == 0) || (c < 32 || (c > 126 && result != 0)))
        {
            // Imprimir mensaje de error en rojo
            ft_putstr(ANSI_COLOR_RED "Error: ft_isprint('");
            if (c >= 32 && c <= 126)
                ft_putchar(c);
            else
                ft_putchar('?'); // Utilizar un placeholder para caracteres no imprimibles
            ft_putstr("') returned ");
            ft_putchar(result == 0 ? '0' : '1');
            ft_putstr(ANSI_COLOR_RESET "\n");
        }
        else
        {
            // Imprimir mensaje correcto en verde
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_isprint('");
            if (c >= 32 && c <= 126)
                ft_putchar(c);
            else
                ft_putchar('?'); // Utilizar un placeholder para caracteres no imprimibles
            ft_putstr("') returned ");
            ft_putchar(result == 0 ? '0' : '1');
            ft_putstr(ANSI_COLOR_RESET "\n");
        }
        c++;
    }
    ft_putstr("Tests completed.\n");
    return 0;
}
