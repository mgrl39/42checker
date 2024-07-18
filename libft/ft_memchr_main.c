#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"

void *ft_memchr(const void *s, int c, size_t n);

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
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
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

void print_memory(void *mem, size_t size)
{
    unsigned char *ptr = (unsigned char *)mem;
    size_t i = 0;
    while (i < size)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126) // Printable characters
            ft_putchar(ptr[i]);
        else
            ft_putchar('.');
        i++;
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

    int test_chars[] = {
        'H', 'o', 'e', 'x', 'A', '\0', 'd', '5', '!', 'F'
    };

    size_t test_sizes[] = {
        13, 10, 26, 26, 12, 1, 7, 43, 0
    };

    int tests_passed = 0;
    int tests_failed = 0;

    printf("Testing ft_memchr function against memchr...\n");

    // Iterate through test cases
    int i = 0;
    while (test_cases[i] != NULL)
    {
        int j = 0;
        while (j < (int)(sizeof(test_chars) / sizeof(test_chars[0])))
        {
            int c = test_chars[j];
            size_t n = test_sizes[i];

            // Using ft_memchr
            void *result_ft = ft_memchr(test_cases[i], c, n);
            // Using memchr from <string.h>
            void *result_std = memchr(test_cases[i], c, n);

            if (result_ft == result_std)
            {
                printf(ANSI_COLOR_GREEN "Test Passed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
                       test_cases[i], c, n, result_ft, result_std);
                tests_passed++;
            }
            else
            {
                printf(ANSI_COLOR_RED "Test Failed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
                       test_cases[i], c, n, result_ft, result_std);
                tests_failed++;
            }

            j++;
        }
        i++;
    }

    // Additional test cases
    printf("\nAdditional Test Cases:\n");

    // Test case for empty string
    printf("\nTesting ft_memchr with empty string:\n");
    char *empty_str = "";
    int c = 'A';
    size_t n = 0;
    void *result_ft = ft_memchr(empty_str, c, n);
    void *result_std = memchr(empty_str, c, n);
    if (result_ft == result_std)
    {
        printf(ANSI_COLOR_GREEN "Test Passed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
               empty_str, c, n, result_ft, result_std);
        tests_passed++;
    }
    else
    {
        printf(ANSI_COLOR_RED "Test Failed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
               empty_str, c, n, result_ft, result_std);
        tests_failed++;
    }

    // Test case for null-terminated string with '\0' character
    printf("\nTesting ft_memchr with null-terminated string containing '\\0':\n");
    char *null_str = "\0Hidden";
    c = '\0';
    n = ft_strlen(null_str); // Search until '\0'
    result_ft = ft_memchr(null_str, c, n);
    result_std = memchr(null_str, c, n);
    if (result_ft == result_std)
    {
        printf(ANSI_COLOR_GREEN "Test Passed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
               null_str, c, n, result_ft, result_std);
        tests_passed++;
    }
    else
    {
        printf(ANSI_COLOR_RED "Test Failed: ft_memchr(\"%s\", '%c', %zu) returned %p, expected %p\n" ANSI_COLOR_RESET,
               null_str, c, n, result_ft, result_std);
        tests_failed++;
    }

    printf("\nSummary:\n");
    printf(ANSI_COLOR_YELLOW "Tests passed: %d\n" ANSI_COLOR_RESET, tests_passed);
    printf(ANSI_COLOR_YELLOW "Tests failed: %d\n" ANSI_COLOR_RESET, tests_failed);

    return 0;
}
