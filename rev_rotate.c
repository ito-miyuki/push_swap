/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:22:29 by mito              #+#    #+#             */
/*   Updated: 2024/01/06 14:38:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		printf("rra\n"); //replace it with ft_printf!!!!
        //ft_printf("rra\n");
}
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		printf("rrb\n"); //replace it with ft_printf!!!!
        //ft_printf("rrb\n");
}
void	rrb(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		printf("rrr\n"); //replace it with ft_printf!!!!
        //ft_printf("rrb\n");
}