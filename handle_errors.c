/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:52:17 by mito              #+#    #+#             */
/*   Updated: 2024/01/26 17:09:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_syntax(char *str_n)
{
    if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
        return (1);
    if ((*str_n == '+' || *str_n == '-') && !(str_n[1] >= '0' && str_n[1] <= '9'))
        return (1);
    while (*++str_n)
    {
        if (!(*str_n >= '0' && *str_n <= '9'))
            return (1);
    }
    return (0);
}

int error_duplicate(t_stack_node *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *temp;
    t_stack_node    *current;

    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        temp = current->next;
        current->nbr = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

void    free_errors(t_stack_node **a)
{
    free_stack(a);
   ft_printf("Error\n");
    exit(1);
}
