#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ANSI color codes for colored output
/*
 * #define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"
*/

// Function prototypes
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
char *ft_strjoin(char const *s1, char const *s2);

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

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	slen;
	size_t	i;

	slen = ft_strlen(src);
	i = 0;
	if (dsize < 1)
		return (slen);
	while (src[i] != '\0' && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	len;

	if (!src)
		return (0);
	if (!dst)
	{
		if (dsize == 0)
			return (ft_strlen(src));
		else
			return (0);
	}
	i = 0;
	while (*dst && i < dsize)
	{
		++dst;
		++i;
	}
	len = ft_strlcpy(dst, src, dsize - i);
	return (len + i);
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

// Test function for ft_strjoin
int ft_strjoin_test(const char *s1, const char *s2, const char *expected)
{
    ft_putstr("Testing ft_strjoin function...\n");

    ft_putstr("String 1: ");
    ft_putstr((char *)s1);
    ft_putstr("\n");

    ft_putstr("String 2: ");
    ft_putstr((char *)s2);
    ft_putstr("\n");

    char *result = ft_strjoin(s1, s2);

    ft_putstr("Joined string: ");
    ft_putstr(result);
    ft_putstr("\n");

    int test_result = 0;
    if (strcmp(result, expected) == 0)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: The joined string matches the expected result\n" ANSI_COLOR_RESET);
        test_result = 1;
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: The joined string does not match the expected result\n" ANSI_COLOR_RESET);
    }

    free(result); // Free the joined string
    return test_result;
}

int main(void)
{
    // Array of test cases
    char *test_cases[][3] = {
        {"Hello", " World!", "Hello World!"},
        {"Foo", "Bar", "FooBar"},
        {"", "Empty", "Empty"},
        {"Empty", "", "Empty"},
        {"", "", ""},
        {"123", "456", "123456"},
        {"ft_", "strjoin", "ft_strjoin"},
        {"Upper", "CASE", "UpperCASE"},
        {"Space", " Test", "Space Test"},
        {"Number", " 123", "Number 123"},
        {NULL, NULL, NULL} // End marker
    };

    int total_tests = 10;
    int tests_passed = 0;
    int tests_failed = 0;

    for (int i = 0; i < total_tests; i++)
    {
        if (ft_strjoin_test(test_cases[i][0], test_cases[i][1], test_cases[i][2]))
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
