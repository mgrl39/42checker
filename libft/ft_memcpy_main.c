#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"

void    *ft_memcpy(void *dest, const void *src, size_t n);

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        ft_putstr("-2147483648");
        return ;
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

void    print_memory(void *mem, size_t size)
{
    unsigned char *ptr;
    size_t  i;

    ptr = (unsigned char *)mem;
    i = 0;
    while (i < size)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126)
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
        i++;
    }
    ft_putstr("\n");
}

int     main(void)
{
    char *test_cases_src[] = {
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

    size_t test_sizes[] = {5, 10, 0, 7, 8, 1, 6, 20};
    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_memcpy function...\n");

    while (test_cases_src[i] != NULL)
    {
        size_t n = test_sizes[i];
        char *src = test_cases_src[i];
        char dst1[50] = {0};
        char dst2[50] = {0};

        // Use ft_memcpy
        ft_memcpy(dst1, src, n);
        // Use standard memcpy
        memcpy(dst2, src, n);

        // Print the memory for visualization
        ft_putstr("Source: \n");
        print_memory(src, n);
        ft_putstr("Custom ft_memcpy result: ");
        print_memory(dst1, sizeof(dst1));
        ft_putstr("Standard memcpy result: ");
        print_memory(dst2, sizeof(dst2));

        // Check if results are equal
        if (memcmp(dst1, dst2, sizeof(dst1)) == 0)
        {
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_memcpy matches standard memcpy\n" ANSI_COLOR_RESET);
            tests_passed++;
        }
        else
        {
            ft_putstr(ANSI_COLOR_RED "Error: ft_memcpy does not match standard memcpy\n" ANSI_COLOR_RESET);
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
