#include "libft.h"
#include "colors.h"
#include <stddef.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strlen(const char *str);

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
        char *test_cases[] = {
                "a",
                "Hello, world!",
                "",
                "42",
                "The quick brown fox jumps over the lazy dog",
                "\0Hidden",
                "1234567890",
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                "0123456789",
                " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
                "Testing more cases including long strings and special characters like é, ñ, and ü",
                NULL
        };
        int tests_passed = 0;
        int tests_failed = 0;
        int i = 0;

        ft_putstr("Testing ft_strlen function...\n");

        while (test_cases[i] != NULL)
        {
                size_t result = ft_strlen(test_cases[i]);
                size_t expected = strlen(test_cases[i]);

                if (result == expected)
                {
                        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strlen(\"");
                        ft_putstr(test_cases[i]);
                        ft_putstr("\") returned ");
                        ft_putnbr(result);
                        ft_putstr(ANSI_COLOR_RESET "\n");
                        tests_passed++;
                }
                else
                {
                        ft_putstr(ANSI_COLOR_RED "Error: ft_strlen(\"");
                        ft_putstr(test_cases[i]);
                        ft_putstr("\") returned ");
                        ft_putnbr(result);
                        ft_putstr(", expected ");
                        ft_putnbr(expected);
                        ft_putstr(ANSI_COLOR_RESET "\n");
                        tests_failed++;
                }
                i++;
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
