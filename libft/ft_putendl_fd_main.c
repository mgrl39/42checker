#include <unistd.h> // Para la función write
#include "colors.h" // Contiene definiciones de colores ANSI

// Prototipo de ft_putstr_fd
void ft_putstr_fd(char *str, int fd)
{
    size_t len = strlen(str);
    write(fd, str, len);
}

// Prototipo de ft_putchar_fd
void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

// Implementación de ft_putendl_fd
void ft_putendl_fd(char *s, int fd);

int main(void)
{
    // Mensaje con ft_putendl_fd (stdout)
    ft_putendl_fd(ANSI_COLOR_BOLD_GREEN "Mensaje con ft_putendl_fd en stdout", 1);

    // Mensaje con ft_putendl_fd (stderr)
    ft_putendl_fd(ANSI_COLOR_BOLD_RED "Mensaje con ft_putendl_fd en stderr", 2);

    // Reiniciar color después de la salida
    ft_putstr_fd(ANSI_COLOR_RESET, 1);
    ft_putstr_fd(ANSI_COLOR_RESET, 2);

    return (0);
}
