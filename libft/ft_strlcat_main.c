#include "colors.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>


#ifndef strlcpy
size_t strlcpy(char *dst, const char *src, size_t dsize) {
    size_t slen;
    size_t i;

    slen = strlen(src);
    i = 0;
    if (dsize < 1)
        return slen;
    while (src[i] != '\0' && i < dsize - 1) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return slen;
}
#endif

// String manipulation functions
#ifndef strlcat
size_t strlcat(char *dst, const char *src, size_t dsize) {
    size_t i;
    size_t len;

    if (!src)
        return 0;
    if (!dst) {
        if (dsize == 0)
            return strlen(src);
        else
            return 0;
    }
    i = 0;
    while (*dst && i < dsize) {
        ++dst;
        ++i;
    }
    len = strlcpy(dst, src, dsize - i);
    return len + i;
}
#endif


size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t dsize);

size_t ft_strlcpy(char *dst, const char *src, size_t size) {
    size_t len_src;
    size_t i;

    if (!dst || !src)
        return 0;
    len_src = 0;
    while (src[len_src] != '\0')
        len_src++;
    if (size > 0) {
        i = 0;
        while (src[i] != '\0' && i < (size - 1)) {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return len_src;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}

size_t ft_strlen(char *str) {
    size_t i = 0;
    while (str[i])
        i++;
    return i;
}

void ft_putnbr(int nb) {
    if (nb == -2147483648) {
        ft_putstr("-2147483648");
        return;
    }
    if (nb < 0) {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        ft_putnbr(nb / 10);
    }
    ft_putchar(nb % 10 + '0');
}

void ft_strlcat_test(char *dst, const char *src, size_t dsize, size_t expected, int *ok_count, int *no_sabes_count) {
    ft_putstr("Testing ft_strlcat function...\n");

    size_t result = ft_strlcat(dst, src, dsize);

    if (result == expected) {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_strlcat returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
        (*ok_count)++;
    } else {
        ft_putstr(ANSI_COLOR_YELLOW "Error: ft_strlcat returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
        (*no_sabes_count)++;
    }
}

int main(void) {
    int ok_count = 0;
    int no_sabes_count = 0;

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

    size_t expected;

    // Test 1: Append within capacity of dst1
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 2: Append exactly at capacity of dst2
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected, &ok_count, &no_sabes_count);

    // Test 3: Empty destination with src1
    expected = strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected, &ok_count, &no_sabes_count);

    // Test 4: Null destination with src1 (should return 0)
    expected = 0;
    ft_strlcat_test(dst4, src1, 20, expected, &ok_count, &no_sabes_count);

    // Test 5: Append empty src2 to dst1
    expected = strlen(dst1);
    ft_strlcat_test(dst1, src2, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 6: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 7: Append src1 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src1);
    ft_strlcat_test(dst2, src1, 12, expected, &ok_count, &no_sabes_count);

    // Test 8: Append src3 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src3);
    ft_strlcat_test(dst1, src3, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 9: Append src4 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src4);
    ft_strlcat_test(dst2, src4, 12, expected, &ok_count, &no_sabes_count);

    // Test 10: Append src2 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src2);
    ft_strlcat_test(dst3, src2, 20, expected, &ok_count, &no_sabes_count);

    // Test 11: Append src5 to dst1 with exact capacity
    expected = ft_strlen(dst1) + strlen(src5);
    ft_strlcat_test(dst1, src5, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 12: Append src3 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src3);
    ft_strlcat_test(dst2, src3, 12, expected, &ok_count, &no_sabes_count);

    // Test 13: Append src4 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src4);
    ft_strlcat_test(dst3, src4, 20, expected, &ok_count, &no_sabes_count);

    // Test 14: Append src1 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src1);
    ft_strlcat_test(dst1, src1, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 15: Append src2 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src2);
    ft_strlcat_test(dst2, src2, 12, expected, &ok_count, &no_sabes_count);

    // Test 16: Append src3 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src3);
    ft_strlcat_test(dst3, src3, 20, expected, &ok_count, &no_sabes_count);

    // Test 17: Append src4 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src4);
    ft_strlcat_test(dst1, src4, dsize1, expected, &ok_count, &no_sabes_count);

    // Test 18: Append src5 to dst2 with exact capacity
    expected = strlen(dst2) + strlen(src5);
    ft_strlcat_test(dst2, src5, 12, expected, &ok_count, &no_sabes_count);

    // Test 19: Append src1 to dst3 with exact capacity
    expected = strlen(dst3) + strlen(src1);
    ft_strlcat_test(dst3, src1, 20, expected, &ok_count, &no_sabes_count);

    // Test 20: Append src2 to dst1 with exact capacity
    expected = strlen(dst1) + strlen(src2);
    ft_strlcat_test(dst1, src2, dsize1, expected, &ok_count, &no_sabes_count);

    // Añadir más tests si es necesario...

    // Resumen final
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(ok_count);
    ft_putstr(" ,");

    ft_putstr(ANSI_COLOR_YELLOW " Tests failed: ");
    ft_putnbr(no_sabes_count);
    ft_putstr(ANSI_COLOR_RESET "\n");

    return 0;
}
