#include <unistd.h>
#include "colors.h"

// Prototype of the function ft_isalnum
int ft_isalnum(int c);

// Prototype of the function ft_putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Prototype of the function ft_putstr 
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

// Prototype of the function ft_putnbr
void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

// Variables globales para contar pruebas pasadas y fallidas
int tests_passed = 0;
int tests_failed = 0;

int main(void)
{
    int c;
    int result;

    c = 0;
    while (c <= 127)
    {
        result = ft_isalnum(c);
      /*
      ((c >= 'a' && c <= 'z' && result == 0) || (c >= 'A' && c <= 'Z' && result == 0)) || 
            ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && result != 0) || (c >= '0' && c <= '9' && result == 0)
      */
        if (((c >= 'a' && c <= 'z' && result == 0) || (c >= 'A' && c <= 'Z' && result == 0) || (c >= '0' && c <= '9' && result == 0)) || 
          (((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9')) && result != 0))
        {
            // Imprimir mensaje de error en rojo
            ft_putstr(ANSI_COLOR_RED "Error: ft_isalnum('");
            ft_putchar(c);
            ft_putstr("') returned ");
            ft_putnbr(result);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_failed++;
        }
        else
        {
            // Imprimir mensaje correcto en verde
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_isalnum('");
            ft_putchar(c);
            ft_putstr("') returned ");
            ft_putnbr(result);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_passed++;
        }
        c++;
    }
    // Imprimir resumen de pruebas
    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return 0;
}
