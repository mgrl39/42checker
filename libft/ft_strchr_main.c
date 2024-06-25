#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <string.h>

// Prototype of ft_strchr
char    *ft_strchr(const char *s, int c);

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    ft_putnbr(int nb)
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
    char *test_cases[] = {
        "Hello, world!",
        "42",
        "The quick brown fox jumps over the lazy dog",
        "Find the character",
        "Another test case",
        "",
        "\0Hidden",
        "1234567890",
        NULL
    };

    int test_chars[] = {
        'H', 'o', 'e', 'x', 'A', '\0', 'd', '5', '!', 'F'
    };

    int tests_passed = 0;
    int tests_failed = 0;

    ft_putstr("Testing ft_strchr function...\n");

    for (int i = 0; test_cases[i] != NULL; i++)
    {
        for (int j = 0; j < sizeof(test_chars) / sizeof(test_chars[0]); j++)
        {
            char *result = ft_strchr(test_cases[i], test_chars[j]);
            char *expected = strchr(test_cases[i], test_chars[j]);

            if (result == expected)
            {
                ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strchr(\"");
                ft_putstr(test_cases[i]);
                ft_putstr("\", '");
                ft_putchar(test_chars[j]);
                ft_putstr("') returned ");
                if (result != NULL)
                {
                    ft_putstr(result);
                }
                else
                {
                    ft_putstr("NULL");
                }
                ft_putstr(ANSI_COLOR_RESET "\n");
                tests_passed++;
            }
            else
            {
                ft_putstr(ANSI_COLOR_RED "Error: ft_strchr(\"");
                ft_putstr(test_cases[i]);
                ft_putstr("\", '");
                ft_putchar(test_chars[j]);
                ft_putstr("') returned ");
                if (result != NULL)
                {
                    ft_putstr(result);
                }
                else
                {
                    ft_putstr("NULL");
                }
                ft_putstr(", expected ");
                if (expected != NULL)
                {
                    ft_putstr(expected);
                }
                else
                {
                    ft_putstr("NULL");
                }
                ft_putstr(ANSI_COLOR_RESET "\n");
                tests_failed++;
            }
        }
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
