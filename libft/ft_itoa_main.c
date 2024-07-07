#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h" // Assuming this header contains ft_itoa declaration
#include "colors.h"

char *ft_itoa(int n);

// Implementation of ft_putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Implementation of ft_putstr
void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

// Implementation of ft_putnbr
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

// Helper function to count digits in an integer
int count_digits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

// Main function to test ft_itoa
int main(void)
{
    int test_cases[] = {0, 12345, -54321, 0, 456, -789, 2147483647, -2147483648};
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);
    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_itoa function...\n");

    while (i < num_cases)
    {
        int n = test_cases[i];
        char *result = ft_itoa(n);
        char *expected = NULL;

        // Determine expected string based on standard library itoa behavior
        expected = (n == 0) ? "0" : NULL;
        if (n == 2147483647)
            expected = "2147483647";
        else if (n == -2147483648)
            expected = "-2147483648";
        else
        {
            expected = malloc((count_digits(n) + 2) * sizeof(char)); // +1 for possible '-' sign, +1 for null terminator
            if (expected)
            {
                snprintf(expected, count_digits(n) + 2, "%d", n);
            }
        }

        // Compare result and expected
        if (result && expected && strcmp(result, expected) == 0)
        {
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_itoa(");
            ft_putnbr(test_cases[i]);
            ft_putstr(") returned ");
            ft_putstr(result);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_passed++;
        }
        else
        {
            ft_putstr(ANSI_COLOR_RED "Error: ft_itoa(");
            ft_putnbr(test_cases[i]);
            ft_putstr(") returned ");
            ft_putstr(result);
            ft_putstr(", expected ");
            ft_putstr(expected);
            ft_putstr(ANSI_COLOR_RESET "\n");
            tests_failed++;
        }

        // Free allocated memory
        free(result);
        if (expected && n != 0 && n != 2147483647 && n != -2147483648)
            free(expected);

        i++;
    }

    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return (0);
}
