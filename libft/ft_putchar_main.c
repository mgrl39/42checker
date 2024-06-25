#include "colors.h"

void	ft_putchar(char c);

static void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	ft_putstr(ANSI_COLOR_PURPLE "If eventually the next message is:\n\"https://github.com/mgrl39/42checker\" (without double quotes) your message is correct");
	ft_putstr(ANSI_COLOR_RESET "\n");
	ft_putstr(ANSI_COLOR_YELLOW "Testing ft_putchar: ");
	ft_putstr(ANSI_COLOR_RESET);
	ft_putchar('h');
	ft_putchar('t');
	ft_putchar('t');
	ft_putchar('p');
	ft_putchar('s');
	ft_putchar(':');
	ft_putchar('/');
	ft_putchar('/');
	ft_putchar('g');
	ft_putchar('i');
	ft_putchar('t');
	ft_putchar('h');
	ft_putchar('u');
	ft_putchar('b');
	ft_putchar('.');
	ft_putchar('c');
	ft_putchar('o');
	ft_putchar('m');
	ft_putchar('/');
	ft_putchar('m');
	ft_putchar('g');
	ft_putchar('r');
	ft_putchar('l');
	ft_putchar('3');
	ft_putchar('9');
	ft_putchar('/');
	ft_putchar('4');
	ft_putchar('2');
	ft_putchar('c');
	ft_putchar('h');
	ft_putchar('e');
	ft_putchar('c');
	ft_putchar('k');
	ft_putchar('e');
	ft_putchar('r');
	ft_putchar('\n');
	return (0);
}
