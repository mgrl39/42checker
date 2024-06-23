#include <unistd.h>
#include "colors.h"

// Prototype of ft_isprint
int ft_isprint(int c);

// Prototype of ft_putchar
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Prototype of ft_putstr 
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

// Prototype of ft_putnbr
void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		nb =  nb % 10;
	}
	ft_putchar(nb + '0');
}

int main(void)
{
    int c;
    int result;
    int tests_passed = 0;
    int tests_failed = 0;

    ft_putstr("Testing ft_isprint function...\n");

    c = 0;
    while (c <= 127)
    {
        result = ft_isprint(c);
        if ((c >= 32 && c <= 126 && result == 0) || ((c < 32 || c > 126) && result != 0))
        {
            // Print error message in red
            ft_putstr(ANSI_COLOR_RED "Error: ft_isprint('");
            if (c >= 32 && c <= 126)
                ft_putchar(c);
            ft_putstr("') returned ");
            ft_putchar(result == 0 ? '0' : '1');
            ft_putstr(ANSI_COLOR_RESET "\n");
	    tests_failed++;
       	}
        else
        {
            // Print correct message in green
            ft_putstr(ANSI_COLOR_GREEN "Correct: ft_isprint('");
            if (c >= 32 && c <= 126)
                ft_putchar(c);
            else
                ft_putchar('?'); // Use a placeholder for non-printable characters
            ft_putstr("') returned ");
            ft_putchar(result == 0 ? '0' : '1');
            ft_putstr(ANSI_COLOR_RESET "\n");
	    tests_passed++;
        }
        c++;
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
