#include "libft.h"
#include "colors.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h> // For standard toupper function

int     ft_toupper(int c);
// Implementation of ft_putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Implementation of ft_putstr
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

// Implementation of ft_putnbr
void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
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

int main(void)
{
    int tests_passed = 0;
    int tests_failed = 0;

    ft_putstr("Testing ft_toupper function...\n");

    int c = 0;
    while (c <= 127)
    {
        int result = ft_toupper(c);
        int expected = toupper(c); // Using standard library toupper as reference

        if (result == expected)
        {
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_toupper('");
            ft_putchar(c);
            ft_putstr("') returned ");
            ft_putchar(result);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_passed++;
        }
        else
        {
            ft_putstr(ANSI_COLOR_RED "Error: ft_toupper('");
            ft_putchar(c);
            ft_putstr("') returned ");
            ft_putchar(result);
            ft_putstr(", expected ");
            ft_putchar(expected);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_failed++;
        }

        c++;
    }

    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return 0;
}
