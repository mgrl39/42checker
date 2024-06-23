#include <unistd.h>

// Prototype of ft_isdigit function
int     ft_isdigit(int c);

// Prototype of ft_putchar
void    ft_putchar(char c)
{
        write(1, &c, 1);
}

// Prototype of ft_putstr 
void    ft_putstr(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                write(1, &str[i], 1);
                i++;
        }
}

int     main(void)
{
        int      c;
        int     result;

        c = 0;
        while (c <= 127) 
        {
                result = ft_isdigit(c);
                if ((c >= '0' && c <= '9' && result == 0) || ((c < '0' || c > '9') && result != 0)) {
                        ft_putstr("Error: ft_isdigit('");
                        ft_putchar(c);
                        ft_putstr("') returned ");
                        if (result == 0)
                                ft_putchar('0');
                        else
                                ft_putchar('1');
                        ft_putstr("\n");
                }
                c++;
        }
        ft_putstr("Tests completed.\n");
        return 0;
}
