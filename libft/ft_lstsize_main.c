#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);

int     ft_lstsize(t_list *lst);
t_list	*ft_lstnew(void *content);

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}


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

// Test function for ft_lstsize
void ft_lstsize_test(t_list *lst, int expected)
{
    ft_putstr("Testing ft_lstsize function...\n");

    int result = ft_lstsize(lst);

    if (result == expected)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_lstsize returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: ft_lstsize returned ");
        ft_putnbr(result);
        ft_putstr(", expected ");
        ft_putnbr(expected);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
}

// Helper function to create a new list node
t_list *create_node(void *content)
{
    t_list *new_node = ft_lstnew(content);
    if (!new_node)
    {
        ft_putstr(ANSI_COLOR_RED "Memory allocation failed" ANSI_COLOR_RESET "\n");
        exit(1);
    }
    return new_node;
}

int main(void)
{
    t_list *list1 = NULL; // Empty list
    t_list *list2 = create_node("Node 1");
    list2->next = create_node("Node 2");
    t_list *list3 = create_node("Node 1");
    list3->next = create_node("Node 2");
    list3->next->next = create_node("Node 3");

    ft_lstsize_test(list1, 0);
    ft_lstsize_test(list2, 2);
    ft_lstsize_test(list3, 3);

    // Free allocated memory
    free(list2->next);
    free(list2);
    free(list3->next->next);
    free(list3->next);
    free(list3);

    return 0;
}
