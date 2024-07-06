#include <unistd.h> // Para la función write
#include "colors.h" // Supongo que "colors.h" contiene definiciones de colores ANSI

void ft_putchar_fd(char c, int fd);

static void ft_putstr_fd(char *str, int fd)
{
    int i = 0;
    while (str[i] != '\0')
    {
        ft_putchar_fd(str[i], fd);
        i++;
    }
}

int main(void)
{
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
