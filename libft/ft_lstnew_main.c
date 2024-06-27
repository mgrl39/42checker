#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function implementations
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
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

// Test function for ft_lstnew
void ft_lstnew_test(void *content)
{
    ft_putstr("Testing ft_lstnew function...\n");

    t_list *node = ft_lstnew(content);

    if (node && node->content == content && node->next == NULL)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_lstnew(");
        if (content == NULL)
        {
            ft_putstr("NULL");
        }
        else
        {
            ft_putstr("\"");
            ft_putstr((char *)content);
            ft_putstr("\"");
        }
        ft_putstr(") created a new node with content ");
        if (node->content == NULL)
        {
            ft_putstr("NULL");
        }
        else
        {
            ft_putstr("\"");
            ft_putstr((char *)node->content);
            ft_putstr("\"");
        }
        ft_putstr(" and next == NULL");
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: ft_lstnew(");
        if (content == NULL)
        {
            ft_putstr("NULL");
        }
        else
        {
            ft_putstr("\"");
            ft_putstr((char *)content);
            ft_putstr("\"");
        }
        ft_putstr(") failed to create a correct node");
        ft_putstr(ANSI_COLOR_RESET "\n");
    }

    free(node);
}

int main(void)
{
    ft_lstnew_test("Hello, world!");
    ft_lstnew_test("42");
    ft_lstnew_test("The quick brown fox");
    ft_lstnew_test("");
    ft_lstnew_test(NULL);

    return 0;
}
