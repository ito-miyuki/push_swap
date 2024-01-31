/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:27:43 by mito              #+#    #+#             */
/*   Updated: 2024/01/31 11:18:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return (false);
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
	return (true);
}

void	ra(t_stack_node **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
}
