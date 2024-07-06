#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "colors.h"
/*
// ANSI color codes for colored output
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"
*/

// Function prototypes
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

// Sample function to apply to each character
char to_uppercase(unsigned int i, char c)
{
    (void)i; // Ignore the index
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    return c;
}

// Test function for ft_strmapi
int ft_strmapi_test(const char *s, char (*f)(unsigned int, char), const char *expected)
{
    ft_putstr("Testing ft_strmapi function...\n");

    ft_putstr("Original string: ");
    ft_putstr((char *)s);
    ft_putstr("\n");

    char *result = ft_strmapi(s, f);

    ft_putstr("Mapped string: ");
    ft_putstr(result);
    ft_putstr("\n");

    int test_result = 0;
    if (strcmp(result, expected) == 0)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: The mapped string matches the expected result\n" ANSI_COLOR_RESET);
        test_result = 1;
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: The mapped string does not match the expected result\n" ANSI_COLOR_RESET);
    }

    free(result); // Free the mapped string
    return test_result;
}

int main(void)
{
    // Define a structure for test cases
    typedef struct {
        const char *input;
        char (*func)(unsigned int, char);
        const char *expected;
    } TestCase;

    // Array of test cases
    TestCase test_cases[] = {
        {"abc", to_uppercase, "ABC"},
        {"hello", to_uppercase, "HELLO"},
        {"123", to_uppercase, "123"},
        {"", to_uppercase, ""},
        {"UPPERCASE", to_uppercase, "UPPERCASE"},
        {"lowerCASE", to_uppercase, "LOWERCASE"},
        {"Mixed123", to_uppercase, "MIXED123"},
        {"HELLO, World!", to_uppercase, "HELLO, WORLD!"},
        {"ft_strmapi", to_uppercase, "FT_STRMAPI"}
    };

    int total_tests = sizeof(test_cases) / sizeof(TestCase);
    int tests_passed = 0;
    int tests_failed = 0;

    for (int i = 0; i < total_tests; i++)
    {
        if (ft_strmapi_test(test_cases[i].input, test_cases[i].func, test_cases[i].expected))
        {
            tests_passed++;
        }
        else
        {
            tests_failed++;
        }
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
