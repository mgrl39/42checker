#include "libft.h"
#include "colors.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototypes
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nb);
void ft_lstadd_front(t_list **lst, t_list *new);
t_list *ft_lstnew(void *content);
t_list *ft_lstlast(t_list *lst);

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

t_list *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        ft_putstr((char *)lst->content);
        if (lst->next)
            ft_putstr(" --> ");
        lst = lst->next;
    }
    ft_putstr("\n");
}

// Test function for ft_lstadd_front
void ft_lstadd_front_test(t_list **lst, t_list *new_node, int expected_size)
{
    ft_putstr("Testing ft_lstadd_front function...\n");

    ft_lstadd_front(lst, new_node);

    int result_size = 0;
    t_list *temp = *lst;
    while (temp)
    {
        result_size++;
        temp = temp->next;
    }

    if (result_size == expected_size)
    {
        ft_putstr(ANSI_COLOR_GREEN "Correct: ft_lstadd_front added the node. List size is now ");
        ft_putnbr(result_size);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }
    else
    {
        ft_putstr(ANSI_COLOR_RED "Error: ft_lstadd_front failed to add the node correctly. List size is ");
        ft_putnbr(result_size);
        ft_putstr(", expected ");
        ft_putnbr(expected_size);
        ft_putstr(ANSI_COLOR_RESET "\n");
    }

    ft_putstr("Current List: ");
    print_list(*lst);
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
    t_list *list = NULL;

    t_list *node1 = create_node("Node 1");
    t_list *node2 = create_node("Node 2");
    t_list *node3 = create_node("Node 3");

    ft_lstadd_front_test(&list, node1, 1);
    ft_lstadd_front_test(&list, node2, 2);
    ft_lstadd_front_test(&list, node3, 3);

    // Free allocated memory
    while (list)
    {
        t_list *temp = list->next;
        free(list);
        list = temp;
    }

    return 0;
}
