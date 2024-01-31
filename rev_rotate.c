/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:22:29 by mito              #+#    #+#             */
/*   Updated: 2024/01/31 11:17:23 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return (false);
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
	return (true);
}

void	rra(t_stack_node **a)
{
	if (rev_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b)
{
	if (rev_rotate(b))
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	if (rev_rotate(a) && rev_rotate(b))
		ft_printf("rrr\n");
}
