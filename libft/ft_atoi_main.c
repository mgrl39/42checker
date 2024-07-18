#include "colors.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>  // Agregamos esta librería para la función write
#include <stdlib.h>  // Agregamos esta librería para la función atoi

// Prototipo de la función ft_atoi
int ft_atoi(const char *nptr);

// Implementación de ft_putchar
void ft_putchar(char c) {
    write(1, &c, 1);
}

// Implementación de ft_putstr
void ft_putstr(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

// Implementación de ft_putnbr
void ft_putnbr(int nb) {
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
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

// Prototipo de la función que escapa strings para impresión
const char *escape_str(const char *str);

// Implementación de single_test_atoi
int single_test_atoi(int test_number, const char *str, int *tests_passed, int *tests_failed) {
    int result = ft_atoi(str);
    int expected = atoi(str);

    if (result == expected) {
        ft_putstr(ANSI_COLOR_GREEN "Correct: " ANSI_COLOR_RESET);
        (*tests_passed)++;
    } else {
        ft_putstr(ANSI_COLOR_RED "Error: " ANSI_COLOR_RESET);
        (*tests_failed)++;
    }

    ft_putstr("Test ");
    ft_putnbr(test_number);
    ft_putstr(": ft_atoi(\"");
    ft_putstr(escape_str(str));
    ft_putstr("\") -> ");
    ft_putnbr(result);
    ft_putstr(", expected -> ");
    ft_putnbr(expected);
    ft_putstr("\n");

    return result == expected;
}

// Implementación de test_atoi
int test_atoi(int *tests_passed, int *tests_failed) {
    char buffer[200];
    int res = 1;

    res = single_test_atoi(1, " \t\v\n\r\f123", tests_passed, tests_failed) && res;
    res = single_test_atoi(2, "0", tests_passed, tests_failed) && res;
    res = single_test_atoi(3, "-1000043", tests_passed, tests_failed) && res;
    res = single_test_atoi(4, "+0000000000000000000000000000000000000000000000000000123", tests_passed, tests_failed) && res;
    res = single_test_atoi(5, "    123", tests_passed, tests_failed) && res;
    res = single_test_atoi(6, "--123", tests_passed, tests_failed) && res;
    res = single_test_atoi(7, "-+123", tests_passed, tests_failed) && res;
    res = single_test_atoi(8, "+-123", tests_passed, tests_failed) && res;
    res = single_test_atoi(9, "++123", tests_passed, tests_failed) && res;
    res = single_test_atoi(10, "- 123", tests_passed, tests_failed) && res;
    res = single_test_atoi(11, "+ 123", tests_passed, tests_failed) && res;
    res = single_test_atoi(12, "+\n123", tests_passed, tests_failed) && res;
    res = single_test_atoi(13, "1209", tests_passed, tests_failed) && res;
    res = single_test_atoi(14, "12/3", tests_passed, tests_failed) && res;
    res = single_test_atoi(15, "12;3", tests_passed, tests_failed) && res;
    res = single_test_atoi(16, "12345", tests_passed, tests_failed) && res;
    res = single_test_atoi(17, "-54321º", tests_passed, tests_failed) && res;
    res = single_test_atoi(18, "      456", tests_passed, tests_failed) && res;
    res = single_test_atoi(19, "+789", tests_passed, tests_failed) && res;
    res = single_test_atoi(20, "	-987", tests_passed, tests_failed) && res;
    res = single_test_atoi(21, "123abc", tests_passed, tests_failed) && res;
    res = single_test_atoi(22, "abc123", tests_passed, tests_failed) && res;
    res = single_test_atoi(23, "++2", tests_passed, tests_failed) && res;
    res = single_test_atoi(24, "-4", tests_passed, tests_failed) && res;
    res = single_test_atoi(25, "--54a", tests_passed, tests_failed) && res;
    res = single_test_atoi(26, "		-2.3", tests_passed, tests_failed) && res;
    res = single_test_atoi(27, "	", tests_passed, tests_failed) && res;
    res = single_test_atoi(28, "	 ", tests_passed, tests_failed) && res;
    res = single_test_atoi(29, "-2147483648", tests_passed, tests_failed) && res;
    res = single_test_atoi(30, "2147483647", tests_passed, tests_failed) && res;

    sprintf(buffer, "%i", INT_MAX);
    res = single_test_atoi(31, buffer, tests_passed, tests_failed) && res;
    sprintf(buffer, "%i", INT_MIN);
    res = single_test_atoi(32, buffer, tests_passed, tests_failed) && res;

    for (int i = 0; i <= 0xFF; i++) {
        sprintf(buffer, "%c %i", i, i + 1);
        res = single_test_atoi(33 + i, buffer, tests_passed, tests_failed) && res;
    }

    return res;
}

// Implementación de escape_str para escapar caracteres especiales en las cadenas
const char *escape_str(const char *str) {
    static char buffer[1024];
    int i = 0, j = 0;
    while (str[i] != '\0' && j < (int)sizeof(buffer) - 4) {
        if (str[i] < 32 || str[i] > 126) {
            j += sprintf(buffer + j, "\\x%02X", (unsigned char)str[i]);
        } else {
            buffer[j++] = str[i];
        }
        i++;
    }
    buffer[j] = '\0';
    return buffer;
}

// Implementación de handle_signals_with_time (dummy function)
void handle_signals_with_time() {
    // Implementación dummy, no hace nada por ahora
}

// main
int main(void) {
    handle_signals_with_time();
    ft_putstr("Testing ft_atoi function...\n");

    int tests_passed = 0;
    int tests_failed = 0;
    test_atoi(&tests_passed, &tests_failed);

    ft_putstr("Summary:\n");
    ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
    ft_putnbr(tests_passed);
    ft_putstr(ANSI_COLOR_RESET ", ");
    ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
    ft_putnbr(tests_failed);
    ft_putstr(ANSI_COLOR_RESET "\n");

    ft_putstr("Tests complete\n");

    return 0;
}
