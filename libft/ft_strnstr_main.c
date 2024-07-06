#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"

// Declaración de la función ft_strnstr
char *ft_strnstr(const char *big, const char *little, size_t len);

void ft_putchar(char c)
{
    write(1, &c, 1);
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

// Definición alternativa de strnstr si no está disponible
#ifndef strnstr
char *strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t needle_len;

    if (*needle == '\0')
        return (char *)haystack;

    needle_len = strlen(needle);
    for (i = 0; i <= len - needle_len; i++)
    {
        if (haystack[i] == needle[0] && strncmp(&haystack[i], needle, needle_len) == 0)
            return (char *)&haystack[i];
    }
    return NULL;
}
#endif

int main(void)
{
    char *test_cases_big[] = {
        "Hello, world!",
        "1234567890",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "!@#$%^&*()_+",
        "The quick brown fox jumps over the lazy dog",
        "This is a simple string",
        "Looking for a needle in a haystack",
        "Just a test string",
        "Pattern matching in strings",
        NULL
    };

    char *test_cases_little[] = {
        "world",
        "456",
        "def",
        "XYZ",
        "&*()",
        "quick",
        "simple",
        "needle",
        "test",
        "strings",
        NULL
    };

    size_t test_sizes[] = {13, 10, 26, 26, 12, 43, 21, 31, 16, 26};
    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_strnstr function...\n");

    while (test_cases_big[i] != NULL)
    {
        const char *big = test_cases_big[i];
        const char *little = test_cases_little[i];
        size_t len = test_sizes[i];

        // Use ft_strnstr
        char *result_ft = ft_strnstr(big, little, len);
        // Use standard strnstr
        char *result_std = strnstr(big, little, len);

        // Print the memory for visualization
        ft_putstr("Big string: \n");
        print_memory(big, strlen(big));
        ft_putstr("Little string: \n");
        print_memory(little, strlen(little));
        ft_putstr("Custom ft_strnstr result: ");
        print_memory(result_ft, result_ft ? strlen(result_ft) : 0);
        ft_putstr("Standard strnstr result: ");
        print_memory(result_std, result_std ? strlen(result_std) : 0);

        // Check if results are equal
        if (result_ft == result_std)
        {
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strnstr matches standard strnstr\n" ANSI_COLOR_RESET);
            tests_passed++;
        }
        else
        {
            ft_putstr(ANSI_COLOR_RED "Error: ft_strnstr does not match standard strnstr\n" ANSI_COLOR_RESET);
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
