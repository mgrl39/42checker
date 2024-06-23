#include <unistd.h>

// Prototipo de la función ft_isalpha
int ft_isalpha(int c);

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

    c = 0;
    while (c <= 127)
    {
        result = ft_isalpha(c);
        if ((c >= '0' && c <= '9' && result == 0) || ((c < '0' || c > '9') && result != 0))
        {
            // Imprimir mensaje de error en rojo
            ft_putstr(ANSI_COLOR_RED "Error: ft_isalpha('");
            ft_putchar(c);
            ft_putstr("') returned ");
            if (result == 0)
                ft_putchar('0');
            else
                ft_putchar('1');
            ft_putstr(ANSI_COLOR_RESET "\n");
        }
        else
        {
            // Imprimir mensaje correcto en verde
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_isalpha('");
            ft_putchar(c);
            ft_putstr("') returned ");
            if (result == 0)
                ft_putchar('0');
            else
                ft_putchar('1');
            ft_putstr(ANSI_COLOR_RESET "\n");
        }
        c++;
    }
    ft_putstr("Tests completed.\n");
    return 0;
}
