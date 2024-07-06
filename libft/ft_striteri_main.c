#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function prototypes
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
void ft_striteri(char *s, void (*f)(unsigned int, char*));

// Function to be used with ft_striteri
void to_uppercase(unsigned int i, char *c)
{
    (void)i; // Ignore index for this function
    if (*c >= 'a' && *c <= 'z')
    {
        *c = *c - 32;
    }
}

// Function implementations
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

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

// Test function for ft_striteri
int ft_striteri_test(char *str, void (*f)(unsigned int, char*), const char *expected)
{
    char *original = strdup(str); // Duplicate the original string for display purposes
    ft_putstr("Testing ft_striteri function...\n");

    ft_putstr("Original string: ");
    ft_putstr(original);
    ft_putstr("\n");

    ft_striteri(str, f);

    ft_putstr("Modified string: ");
    ft_putstr(str);
    ft_putstr("\n");

    int result = 0;
    if (strcmp(str, expected) == 0)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: The modified string matches the expected result\n" ANSI_COLOR_RESET);
        result = 1;
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: The modified string does not match the expected result\n" ANSI_COLOR_RESET);
    }

    free(original); // Free the duplicated string
    return result;
}

int main(void)
{
    // Array of test cases
    char *test_cases[] = {
        "abc", "ABC", "123", "Hello, World!", "",
        "aBcDeF", "HeLlO wOrLd", "42Seoul", "tEsT cAsE", "AnotherTest",
        "lowercase", "UPPERCASE", "1234567890", "!@#$%^&*()", "mixedCASE",
        "short", "looooooooooooooooong", "MiXeD1234", "edgeCASE", "simple",
        NULL
    };
    // Array of expected results
    char *expected_results[] = {
        "ABC", "ABC", "123", "HELLO, WORLD!", "",
        "ABCDEF", "HELLO WORLD", "42SEOUL", "TEST CASE", "ANOTHERTEST",
        "LOWERCASE", "UPPERCASE", "1234567890", "!@#$%^&*()", "MIXEDCASE",
        "SHORT", "LOOOOOOOOOOOOOOOOONG", "MIXED1234", "EDGECASE", "SIMPLE"
    };

    int total_tests = 20;
    int tests_passed = 0;
    int tests_failed = 0;

    for (int i = 0; i < total_tests; i++)
    {
        char *str = strdup(test_cases[i]);
        if (ft_striteri_test(str, to_uppercase, expected_results[i]))
        {
            tests_passed++;
        }
        else
        {
            tests_failed++;
        }
        free(str);
    }

    // Print summary
    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return 0;
}
