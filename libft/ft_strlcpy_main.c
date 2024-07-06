#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dsize);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return;
    }
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}

void print_memory(const void *mem, size_t size)
{
    const unsigned char *ptr = (const unsigned char *)mem;
    for (size_t i = 0; i < size; i++)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
    }
    ft_putstr("\n");
}

int main(void)
{
    char *test_cases[] = {
        "Hello, world!",
        "1234567890",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "!@#$%^&*()_+",
        "",
        "\0Hidden",
        "The quick brown fox jumps over the lazy dog",
        NULL
    };

    size_t test_sizes[] = {5, 10, 0, 7, 8, 1, 6, 20, 15, 25, 50, 100};
    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_strlcpy function...\n");

    while (test_cases[i] != NULL)
    {
        for (size_t j = 0; j < sizeof(test_sizes) / sizeof(test_sizes[0]); j++)
        {
            size_t n = test_sizes[j];
            char src[100];
            char dst1[100] = {0};
            char dst2[100] = {0};

            strncpy(src, test_cases[i], sizeof(src) - 1);
            src[sizeof(src) - 1] = '\0';

            // Use ft_strlcpy
            size_t result_ft = ft_strlcpy(dst1, src, n);
            // Use standard strlcpy
            size_t result_std = strlcpy(dst2, src, n);

            // Print the memory for visualization
            ft_putstr("Source: \n");
            print_memory(src, n);
            ft_putstr("Custom ft_strlcpy result: ");
            print_memory(dst1, sizeof(dst1));
            ft_putstr("Standard strlcpy result: ");
            print_memory(dst2, sizeof(dst2));

            // Check if results are equal
            if (result_ft == result_std && strcmp(dst1, dst2) == 0)
            {
                ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strlcpy matches standard strlcpy\n" ANSI_COLOR_RESET);
                tests_passed++;
            }
            else
            {
                ft_putstr(ANSI_COLOR_RED "Error: ft_strlcpy does not match standard strlcpy\n" ANSI_COLOR_RESET);
                tests_failed++;
            }
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
