/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:11:18 by mito              #+#    #+#             */
/*   Updated: 2024/01/22 19:03:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;
	
	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long	min_num;
	t_stack_node *min_node;

	if (!stack)
		return (NULL);
	min_num = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < min_num)
		{
			min_num = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
t_stack_node	*find_max(t_stack_node *stack)
{
	long	max_num;
	t_stack_node *max_node;

	if (!stack)
		return (NULL);
	max_num = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_num)
		{
			max_num = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}