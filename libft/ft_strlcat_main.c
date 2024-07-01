#include "colors.h"
#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	if (!dst || !src)
		return (0);
	len_src = 0;
	while (src[len_src] != '\0')
		len_src++;
	if (size > 0)
	{
		i = 0;
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

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

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
void ft_putnbr(int nb)
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
    {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

void ft_strlcat_test(char *dst, const char *src, size_t dsize, size_t expected)
{
    ft_putstr("Testing ft_strlcat function...\n");

    size_t result = ft_strlcat(dst, src, dsize);

    if (result == expected)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strlcat returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: ft_strlcat returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
}

int main(void)
{
    char dst1[20] = "Hello";
    char dst2[12] = "Hello";
    char dst3[20] = "";
    char *dst4 = NULL;
    char src1[] = " World!";
    char src2[] = "";
    char src3[] = "Testing ft_strlcat function with a very long source string that exceeds the destination buffer size";
    char src4[] = "Another test";
    char src5[] = "1234567890123456789012345678901234567890"; // 40 characters long

    size_t dsize1 = sizeof(dst1) / sizeof(dst1[0]);
    size_t dsize2 = sizeof(dst2) / sizeof(dst2[0]);

    size_t expected;

    // Test 1: Append within capacity of dst1
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected);

    // Test 2: Append exactly at capacity of dst2
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected);

    // Test 3: Empty destination with src1
    expected = strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected);

    // Test 4: Null destination with src1 (should return 0)
    expected = 0;
    ft_strlcat_test(dst4, src1, 20, expected);

    // Test 5: Append empty src2 to dst1
    expected = strlen(dst1);
    ft_strlcat_test(dst1, src2, dsize1, expected);

    // Test 6: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected);

    // Test 7: Append src1 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected);

    // Test 8: Append src3 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src3);
    ft_strlcat_test(dst1, src3, dsize1, expected);

    // Test 9: Append src4 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src4);
    ft_strlcat_test(dst2, src4, 12, expected);

    // Test 10: Append src2 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src2);
    ft_strlcat_test(dst3, src2, 20, expected);

    // Test 11: Append src5 to dst1 with exact capacity
    expected = ft_strlen(dst1) + strlen(src5);
    ft_strlcat_test(dst1, src5, dsize1, expected);

    // Test 12: Append src3 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src3);
    ft_strlcat_test(dst2, src3, 12, expected);

    // Test 13: Append src4 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src4);
    ft_strlcat_test(dst3, src4, 20, expected);

    // Test 14: Append src1 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected);

    // Test 15: Append src2 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src2);
    ft_strlcat_test(dst2, src2, 12, expected);

    // Test 16: Append src3 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src3);
    ft_strlcat_test(dst3, src3, 20, expected);

    // Test 17: Append src4 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src4);
    ft_strlcat_test(dst1, src4, dsize1, expected);

    // Test 18: Append src5 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src5);
    ft_strlcat_test(dst2, src5, 12, expected);

    // Test 19: Append src1 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected);

    // Test 20: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected);

    // Test 21: Append src3 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src3);
    ft_strlcat_test(dst2, src3, 12, expected);

    // Test 22: Append src4 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src4);
    ft_strlcat_test(dst3, src4, 20, expected);

    // Test 23: Append src5 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src5);
    ft_strlcat_test(dst1, src5, dsize1, expected);

    // Test 24: Append src1 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected);

    // Test 25: Append src2 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src2);
    ft_strlcat_test(dst3, src2, 20, expected);

    // Test 26: Append src3 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src3);
    ft_strlcat_test(dst1, src3, dsize1, expected);

    // Test 27: Append src4 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src4);
    ft_strlcat_test(dst2, src4, 12, expected);

    // Test 28: Append src5 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src5);
    ft_strlcat_test(dst3, src5, 20, expected);

    // Test 29: Append src1 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected);

    // Test 30: Append src2 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src2);
    ft_strlcat_test(dst2, src2, 12, expected);

    // Test 31: Append src3 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src3);
    ft_strlcat_test(dst3, src3, 20, expected);

    // Test 32: Append src4 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src4);
    ft_strlcat_test(dst1, src4, dsize1, expected);

    // Test 33: Append src5 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src5);
    ft_strlcat_test(dst2, src5, 12, expected);

    // Test 34: Append src1 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected);

    // Test 35: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected);

    // Test 36: Append src3 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src3);
    ft_strlcat_test(dst2, src3, 12, expected);

    // Test 37: Append src4 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src4);
    ft_strlcat_test(dst3, src4, 20, expected);

    // Test 38: Append src5 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src5);
    ft_strlcat_test(dst1, src5, dsize1, expected);

    // Test 39: Append src1 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected);

    // Test 40: Append src2 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src2);
    ft_strlcat_test(dst3, src2, 20, expected);

    // Test 41: Append src3 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src3);
    ft_strlcat_test(dst1, src3, dsize1, expected);

    // Test 42: Append src4 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src4);
    ft_strlcat_test(dst2, src4, 12, expected);

    // Test 43: Append src5 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src5);
    ft_strlcat_test(dst3, src5, 20, expected);

    // Test 44: Append src1 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected);

    // Test 45: Append src2 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src2);
    ft_strlcat_test(dst2, src2, 12, expected);

    // Test 46: Append src3 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src3);
    ft_strlcat_test(dst3, src3, 20, expected);

    // Test 47: Append src4 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src4);
    ft_strlcat_test(dst1, src4, dsize1, expected);

    // Test 48: Append src5 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src5);
    ft_strlcat_test(dst2, src5, 12, expected);

    // Test 49: Append src1 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected);

    // Test 50: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected);

    return 0;
}

