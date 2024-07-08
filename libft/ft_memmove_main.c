#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "colors.h"

typedef struct {
    char *dest;
    const char *src;
    size_t n;
} TestCase;

void	*ft_memmove(void *dest, const void *src, size_t n);

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
/*
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	len = i;
	while (src[i - len] && i + 1 < dstsize)
	{
		dst[i] = src[i - len];
		i++;
	}
	if (len < dstsize)
		dst[i] = '\0';
	return (len + ft_strlen(src));
}
*/

void ft_memmove_test(char *dest, const char *src, size_t n, int *passed, int *failed)
{
    char dest_std[100];
    char dest_ft[100];

    // Copy initial data to test buffers
    strcpy(dest_std, dest);
    strcpy(dest_ft, dest);

    // Perform standard memmove
    memmove(dest_std, src, n);
    // Perform ft_memmove
    ft_memmove(dest_ft, src, n);

    // Compare results
    if (memcmp(dest_std, dest_ft, strlen(dest_std) + 1) == 0) {
        printf(ANSI_COLOR_GREEN "Correct: Memory after ft_memmove matches the standard memmove result\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "Buffer: '%s'\n" ANSI_COLOR_RESET, dest_ft);
        (*passed)++;
    } else {
        printf(ANSI_COLOR_RED "Error: Memory after ft_memmove does not match the standard memmove result\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "Standard memmove result: '%s'\n" ANSI_COLOR_RESET, dest_std);
        printf(ANSI_COLOR_RED "ft_memmove result: '%s'\n" ANSI_COLOR_RESET, dest_ft);
        (*failed)++;
    }
}

int main(void)
{
    int passed = 0;
    int failed = 0;

    char dest1[100] = "abcdef";
    char src1[100] = "ghijkl";
    char dest2[100] = "abcdef";
    char src2[100] = "ghijkl";
    char dest3[100] = "abcdef";
    char src3[100] = "abcdef";
    char dest4[100] = "abcdef";
    char src4[100] = "abcdef";
    char dest5[100] = "abcdef";
    char src5[100] = "abcdef";
    char dest6[100] = "initial";
    char src6[100] = "";
    char dest7[100] = "initial";
    char src7[100] = "test";
    char dest8[100] = "test";
    char src8[100] = "initial";
    char dest9[100] = "123456789";
    char src9[100] = "123456789";
    char dest10[100] = "123456789";
    char src10[100] = "123456789";

    char dest11[100] = "overlap";
    char dest12[100] = "abc123def";
    char src12[100] = "456";
    char dest13[100] = "abcdef";
    char dest14[100] = "abcdef";

    TestCase test_cases[] = {
        { dest1, src1, 6 },
        { dest2, src2, 3 },
        { dest3, src3, 6 },
        { dest4, src4, 3 },
        { dest5, src5, 0 },
        { dest6, src6, 0 },
        { dest7, src7, 4 },
        { dest8, src8, 4 },
        { dest9, src9, 9 },
        { dest10, src10, 4 },

        // Casos con solapamiento
        { dest11, dest11 + 3, 4 },
        { dest12, src12, 3 },
        { dest13, dest13 + 2, 4 },
        { dest14, dest14 + 3, 3 },
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Testing ft_memmove function...\n");

    for (int i = 0; i < num_tests; i++) {
        printf("Test case %d\n", i + 1);
        ft_memmove_test(test_cases[i].dest, test_cases[i].src, test_cases[i].n, &passed, &failed);
    }

    printf(ANSI_COLOR_YELLOW "\nPassed: %d, " ANSI_COLOR_RESET, passed);
    printf(ANSI_COLOR_YELLOW "Failed: %d\n" ANSI_COLOR_RESET, failed);

    return 0;
}

void ft_memmove_test(char *dest, const char *src, size_t n, int *passed, int *failed)
{
    char dest_std[100];
    char dest_ft[100];

    // Copy initial data to test buffers
    strcpy(dest_std, dest);
    strcpy(dest_ft, dest);

    // Perform standard memmove
    memmove(dest_std, src, n);
    // Perform ft_memmove
    ft_memmove(dest_ft, src, n);

    // Compare results
    if (memcmp(dest_std, dest_ft, strlen(dest_std) + 1) == 0) {
        printf(ANSI_COLOR_GREEN "Correct: Memory after ft_memmove matches the standard memmove result\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_GREEN "Buffer: '%s'\n" ANSI_COLOR_RESET, dest_ft);
        (*passed)++;
    } else {
        printf(ANSI_COLOR_RED "Error: Memory after ft_memmove does not match the standard memmove result\n" ANSI_COLOR_RESET);
        printf(ANSI_COLOR_RED "Standard memmove result: '%s'\n" ANSI_COLOR_RESET, dest_std);
        printf(ANSI_COLOR_RED "ft_memmove result: '%s'\n" ANSI_COLOR_RESET, dest_ft);
        (*failed)++;
    }
}

int main(void)
{
    int passed = 0;
    int failed = 0;

    char dest1[100] = "abcdef";
    char src1[100] = "ghijkl";
    char dest2[100] = "abcdef";
    char src2[100] = "ghijkl";
    char dest3[100] = "abcdef";
    char src3[100] = "abcdef";
    char dest4[100] = "abcdef";
    char src4[100] = "abcdef";
    char dest5[100] = "abcdef";
    char src5[100] = "abcdef";
    char dest6[100] = "initial";
    char src6[100] = "";
    char dest7[100] = "initial";
    char src7[100] = "test";
    char dest8[100] = "test";
    char src8[100] = "initial";
    char dest9[100] = "123456789";
    char src9[100] = "123456789";
    char dest10[100] = "123456789";
    char src10[100] = "123456789";

    char dest11[100] = "overlap";
    char dest12[100] = "abc123def";
    char src12[100] = "456";
    char dest13[100] = "abcdef";
    char dest14[100] = "abcdef";

    TestCase test_cases[] = {
        { dest1, src1, 6 },
        { dest2, src2, 3 },
        { dest3, src3, 6 },
        { dest4, src4, 3 },
        { dest5, src5, 0 },
        { dest6, src6, 0 },
        { dest7, src7, 4 },
        { dest8, src8, 4 },
        { dest9, src9, 9 },
        { dest10, src10, 4 },

        // Casos con solapamiento
        { dest11, dest11 + 3, 4 },
        { dest12, src12, 3 },
        { dest13, dest13 + 2, 4 },
        { dest14, dest14 + 3, 3 },
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Testing ft_memmove function...\n");

    for (int i = 0; i < num_tests; i++) {
        printf("Test case %d\n", i + 1);
        ft_memmove_test(test_cases[i].dest, test_cases[i].src, test_cases[i].n, &passed, &failed);
    }

    printf(ANSI_COLOR_YELLOW "\nPassed: %d, " ANSI_COLOR_RESET, passed);
    printf(ANSI_COLOR_YELLOW "Failed: %d\n" ANSI_COLOR_RESET, failed);

    return 0;
}
