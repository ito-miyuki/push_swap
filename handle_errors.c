/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:52:17 by mito              #+#    #+#             */
/*   Updated: 2024/01/20 15:02:37 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    printf("Error\n"); //replace it with ft_printf
    // ft_printf("Error\n");
    exit(1);
}