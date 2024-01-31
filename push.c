/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:59 by mito              #+#    #+#             */
/*   Updated: 2024/01/31 11:14:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (*src == NULL)
		return (false);
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (*dst == NULL)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
	return (true);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (push(a, b))
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	if (push(b, a))
		ft_printf("pb\n");
}
