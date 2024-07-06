#include <unistd.h> // Para la función write
#include "colors.h" // Contiene definiciones de colores ANSI

void ft_putstr_fd(char *str, int fd); // Prototipo de ft_putstr_fd

size_t  ft_strlen(char *str)
{
        size_t  i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}
int main(void)
{
    // Prototipo de ft_putchar_fd
    void ft_putchar_fd(char c, int fd)
    {
        write(fd, &c, 1);
    }

    // Mensaje inicial en color naranja claro (stdout)
    ft_putstr_fd(ANSI_COLOR_BOLD_YELLOW "If you see both the following message and the link, then your message is correct:\n", 1);
    ft_putstr_fd("\"https://github.com/mgrl39/42checker\" (without double quotes)\n", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "Testing ft_putchar_fd: ", 1);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "https://github.com/mgrl39/42checker", 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd(ANSI_COLOR_RESET, 1);

    // Mensaje en descriptor 2 en color naranja (stderr)
    ft_putstr_fd(ANSI_COLOR_BOLD_YELLOW "\nNow in descriptor 2:\n", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_YELLOW "\"https://github.com/mgrl39\" (without double quotes)\n", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_RED "Testing ft_putchar_fd: ", 2);
    ft_putstr_fd(ANSI_COLOR_BOLD_CYAN "https://github.com/mgrl39", 2);
    ft_putchar_fd('\n', 2);

    return (0);
}
