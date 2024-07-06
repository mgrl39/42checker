#include <unistd.h> // Para la función write
#include <string.h> // Para la función strlen
#include "colors.h" // Contiene definiciones de colores ANSI
#include "libft.h"  // Contiene las definiciones de ft_putstr_fd, ft_putchar_fd, y ft_putnbr_fd

void ft_putstr_fd(char *str, int fd)
{
    size_t len = strlen(str);
    write(fd, str, len);
}

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void ft_putnbr_fd(int n, int fd);

int main(void)
{
    // Casos de prueba para ft_putnbr_fd en stdout
    ft_putstr_fd(ANSI_COLOR_BOLD_YELLOW "Testing ft_putnbr_fd with stdout:\n", 1);

    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE "Number: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "42", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE " -> ", 1);
    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE "Number: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "-42", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE " -> ", 1);
    ft_putnbr_fd(-42, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE "Number: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "0", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE " -> ", 1);
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE "Number: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "-2147483648", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE " -> ", 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);

    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE "Number: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "2147483647", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_BLUE " -> ", 1);
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);

    // Reiniciar color después de la salida
    ft_putstr_fd(ANSI_COLOR_RESET, 1);

    // Casos de prueba para ft_putnbr_fd en stderr
    ft_putstr_fd(ANSI_COLOR_BOLD_YELLOW "Testing ft_putnbr_fd with stderr:\n", 2);

    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN "Number: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "42", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN " -> ", 2);
    ft_putnbr_fd(42, 2);
    ft_putchar_fd('\n', 2);

    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN "Number: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "-42", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN " -> ", 2);
    ft_putnbr_fd(-42, 2);
    ft_putchar_fd('\n', 2);

    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN "Number: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "0", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN " -> ", 2);
    ft_putnbr_fd(0, 2);
    ft_putchar_fd('\n', 2);

    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN "Number: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "-2147483648", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN " -> ", 2);
    ft_putnbr_fd(-2147483648, 2);
    ft_putchar_fd('\n', 2);

    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN "Number: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "2147483647", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_GREEN " -> ", 2);
    ft_putnbr_fd(2147483647, 2);
    ft_putchar_fd('\n', 2);

    // Reiniciar color después de la salida
    ft_putstr_fd(ANSI_COLOR_RESET, 2);

    return (0);
}
