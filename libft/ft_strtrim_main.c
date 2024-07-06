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
char *ft_strtrim(char const *s1, char const *set);

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;
	size_t		i;

	i = 0;
	if (!src)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	dstsize--;
	while (dstsize > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = '\0';
	return (len);
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

// Test function for ft_strtrim
int ft_strtrim_test(const char *s1, const char *set, const char *expected)
{
    ft_putstr("Testing ft_strtrim function...\n");

    ft_putstr("Original string: ");
    ft_putstr((char *)s1);
    ft_putstr("\n");

    ft_putstr("Set of characters to trim: ");
    ft_putstr((char *)set);
    ft_putstr("\n");

    char *result = ft_strtrim(s1, set);

    ft_putstr("Trimmed string: ");
    ft_putstr(result);
    ft_putstr("\n");

    int test_result = 0;
    if (strcmp(result, expected) == 0)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: The trimmed string matches the expected result\n" ANSI_COLOR_RESET);
        test_result = 1;
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: The trimmed string does not match the expected result\n" ANSI_COLOR_RESET);
    }

    free(result); // Free the trimmed string
    return test_result;
}

int main(void)
{
    // Define a structure for test cases
    typedef struct {
        const char *input;
        const char *set;
        const char *expected;
    } TestCase;

    TestCase test_cases[] = {
        {"   hello   ", " ", "hello"},
        {"--hello--", "-", "hello"},
        {"  abc  def  ", " ", "abc  def"},
        {"xyz", "xyz", ""},
        {"abc", "", "abc"},
        {"   ", " ", ""},
        {"123hello321", "123", "hello"},
        {"!!!hello!!!", "!", "hello"},
        {"trim me", " ", "trim me"},
        {"   leading spaces", " ", "leading spaces"},
        {"trailing spaces   ", " ", "trailing spaces"},
        {"--------", "-", ""},
        {"", "", ""},
        {"\t\t\ttabs\t\t\t", "\t", "tabs"},
        {"^&^&^&hello^&^&^&", "^&", "hello"},
        {"\n\n\nnewlines\n\n\n", "\n", "newlines"},
        {" !@#$%^&*(){}[]|\\;:'\",.<>/?", " !@#$%^&*(){}[]|\\;:'\",.<>/?", ""},
        {"  \\ \\\\ \\n\\n\\t\\ttrimmed  \\t\\t\\n\\n  ", " \\n\\t", "rimmed"}
    };

    /*
    // Array of test cases
    TestCase test_cases[] = {
        {"   hello   ", " ", "hello"},
        {"--hello--", "-", "hello"},
        {"  abc  def  ", " ", "abc  def"},
        {"xyz", "xyz", ""},
        {"abc", "", "abc"},
        {"   ", " ", ""},
        {"123hello321", "123", "hello"},
        {"!!!hello!!!", "!", "hello"},
        {"trim me", " ", "trim me"},
        {"   leading spaces", " ", "leading spaces"},
        {"trailing spaces   ", " ", "trailing spaces"}
    };
*/
    int total_tests = sizeof(test_cases) / sizeof(TestCase);
    int tests_passed = 0;
    int tests_failed = 0;

    for (int i = 0; i < total_tests; i++)
    {
        if (ft_strtrim_test(test_cases[i].input, test_cases[i].set, test_cases[i].expected))
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
