#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include "colors.h" // Assumiendo que este header define códigos de color ANSI para la salida en terminal

void    ft_putchar(char c)
{
        write(1, &c, 1);
}
void    ft_putstr(char *str)
{
        while (*str)
                ft_putchar(*str++);
}

void ft_bzero(void *s, size_t n)
{
        size_t  i;
        unsigned char *p;

        i = 0;
        p = (unsigned char *)s;
        while (i < n)
        {
                p[i] = 0;
                i++;
        }
}

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


// Función auxiliar para imprimir el contenido de la memoria
void print_memory(void *mem, size_t size)
{
    unsigned char *ptr = (unsigned char *)mem;
    size_t i = 0;
    while (i < size)
    {
        if (ptr[i] >= 32 && ptr[i] <= 126) // Caracteres imprimibles
            putchar(ptr[i]);
        else
            putchar('.');
        i++;
    }
    putchar('\n');
}

int main(void)
{
    int tests_passed = 0;
    int tests_failed = 0;

    ft_putstr("Testing ft_calloc function...\n");

    // Casos de prueba
    size_t test_sizes[] = {0, 1, 10, 100};
    size_t test_counts[] = {0, 1, 5, 3};

    size_t size_index = 0;
    while (size_index < sizeof(test_sizes) / sizeof(test_sizes[0]))
    {
        size_t size = test_sizes[size_index];
        size_t count_index = 0;
        while (count_index < sizeof(test_counts) / sizeof(test_counts[0]))
        {
            size_t count = test_counts[count_index];

            ft_putstr("\nTest ft_calloc(");
            ft_putnbr(count);
            ft_putstr(", ");
            ft_putnbr(size);
            ft_putstr("):\n");

            // Utilizando ft_calloc
            void *result = ft_calloc(count, size);
            if (result)
            {
                // Verificar si la memoria está inicializada a cero
                int is_zeroed = 1;
                unsigned char *ptr = (unsigned char *)result;
                size_t k = 0;
                while (k < count * size)
                {
                    if (ptr[k] != 0)
                    {
                        is_zeroed = 0;
                        break;
                    }
                    k++;
                }

                if (is_zeroed)
                {
                    printf(ANSI_COLOR_GREEN "Test Passed: Memory allocated by ft_calloc is zero-initialized\n" ANSI_COLOR_RESET);
                    tests_passed++;
                }
                else
                {
                    printf(ANSI_COLOR_RED "Test Failed: Memory allocated by ft_calloc is not zero-initialized\n" ANSI_COLOR_RESET);
                    tests_failed++;
                }

                // Imprimir el contenido de la memoria para verificar
                printf("Memory content:\n");
                print_memory(result, count * size);

                // Liberar la memoria asignada
                free(result);
            }
            else
            {
                printf(ANSI_COLOR_RED "Test Failed: ft_calloc returned NULL\n" ANSI_COLOR_RESET);
                tests_failed++;
            }

            count_index++;
        }

        size_index++;
    }

    // Resumen
    printf("\nSummary:\n");
    printf(ANSI_COLOR_YELLOW "Tests passed: %d\n", tests_passed);
    printf("Tests failed: %d\n" ANSI_COLOR_RESET, tests_failed);

    return 0;
}
