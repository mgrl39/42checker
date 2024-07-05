#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de ft_strdup
char *ft_strdup(const char *s);

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
// Función para imprimir un solo carácter
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Función para imprimir una cadena de caracteres
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

// Función para imprimir un entero
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

int main(void)
{
	char *test_cases[] = {
    "Hello, world!",
    "1234567890",
    "",
    "The quick brown fox jumps over the lazy dog",
    "\0Hidden",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",
    "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
    "áéíóúñ",
    "Café ☕",
    "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.",
    "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
    "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~",
    NULL
};

    int tests_passed = 0;
    int tests_failed = 0;
    int i = 0;

    ft_putstr("Testing ft_strdup function...\n");

while (test_cases[i] != NULL)
{
	char *result_ft = ft_strdup(test_cases[i]);
	char *result_std = strdup(test_cases[i]);

	// Comparar los resultados
	if (result_ft != NULL && result_std != NULL && strcmp(result_ft, result_std) == 0)
	{
		ft_putstr(ANSI_COLOR_GREEN "Test Passed: ft_strdup(\"");
		ft_putstr(test_cases[i]);
		ft_putstr("\") returned \"");
		ft_putstr(result_ft);
		ft_putstr("\" as expected.\n" ANSI_COLOR_RESET);
		tests_passed++;
	}
	else
	{
		ft_putstr(ANSI_COLOR_RED "Test Failed: ft_strdup(\"");
		ft_putstr(test_cases[i]);
		ft_putstr("\") returned \"");
		ft_putstr(result_ft);
		ft_putstr("\", expected \"");
		ft_putstr(result_std);
		ft_putstr("\".\n" ANSI_COLOR_RESET);
		tests_failed++;
	}

	// Liberar memoria
	free(result_ft);
	free(result_std);

	i++;
}

ft_putstr("Summary:\n");
ft_putstr(ANSI_COLOR_YELLOW "Tests passed: ");
ft_putnbr(tests_passed);
ft_putstr(ANSI_COLOR_RESET ", ");
ft_putstr(ANSI_COLOR_YELLOW "Tests failed: ");
ft_putnbr(tests_failed);
ft_putstr(ANSI_COLOR_RESET "\n");

return 0;
}
