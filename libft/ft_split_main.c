#include "libft.h"  // Assumed to contain necessary prototypes
#include <stdio.h>
#include <stdlib.h>  // For malloc, free

// Function prototypes
static int count_words(char const *s, char c);
static char *get_next_word(char const *s, char c, int *start);
static void free_result(char **result);
char **ft_split(char const *s, char c);


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}


char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

// Test function for ft_split
int ft_split_test(char const *s, char c, char **expected)
{
    printf("Testing ft_split function...\n");

    printf("Original string: %s\n", s);

    char **result = ft_split(s, c);

    printf("Split string:\n");
    if (!result)
    {
        printf("Returned NULL\n");
    }
    else
    {
        int i = 0;
        while (result[i])
        {
            printf("[%d]: %s\n", i, result[i]);
            i++;
        }
    }

    int test_result = 0;
    // Compare result with expected
    if (expected == NULL && result == NULL)
    {
        printf("\x1b[32mCorrect: Both expected and result are NULL\x1b[0m\n");
        test_result = 1;
    }
    else if (expected == NULL || result == NULL)
    {
        printf("\x1b[31mError: One of expected or result is NULL, but not both\x1b[0m\n");
    }
    else
    {
        int match = 1;
        int i = 0;
        while (expected[i] && result[i])
        {
            if (strcmp(expected[i], result[i]) != 0)
            {
                match = 0;
                break;
            }
            i++;
        }
        if (match && expected[i] == NULL && result[i] == NULL)
        {
            printf("\x1b[32mCorrect: Split strings match expected result\x1b[0m\n");
            test_result = 1;
        }
        else
        {
            printf("\x1b[31mError: Split strings do not match expected result\x1b[0m\n");
        }
    }

    // Free result
    free_result(result);

    return test_result;
}

int main(void)
{
    // Test cases
    char const *test_strings[] = {
        "hello,world",          // Expected: ["hello", "world", NULL]
        "one/two/three",        // Expected: ["one", "two", "three", NULL]
        "split,with,,empty",     // Expected: ["split", "with", "", "empty", NULL]
        "onlyone",              // Expected: ["onlyone", NULL]
        "",                     // Expected: [NULL]
        "no delimiters",        // Expected: ["no delimiters", NULL]
        "leading,comma",        // Expected: ["leading", "comma", NULL]
        "trailing,comma,",      // Expected: ["trailing", "comma", "", NULL]
        NULL                    // End of test cases marker
    };

    char const delimiter = ',';
    char *expected_results[][5] = {
        {"hello", "world", NULL},
        {"one", "two", "three", NULL},
        {"split", "with", "", "empty", NULL},
        {"onlyone", NULL},
        {NULL},
        {"no delimiters", NULL},
        {"leading", "comma", NULL},
        {"trailing", "comma", "", NULL}
    };

    int i = 0;
    int tests_passed = 0;
    int tests_failed = 0;

    while (test_strings[i])
    {
        printf("\nTest Case %d:\n", i + 1);
        if (ft_split_test(test_strings[i], delimiter, expected_results[i]))
        {
            tests_passed++;
        }
        else
        {
            tests_failed++;
        }
        i++;
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Tests passed: \x1b[33m%d\x1b[0m, Tests failed: \x1b[31m%d\x1b[0m\n", tests_passed, tests_failed);

    return 0;
}
