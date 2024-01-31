/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/31 11:06:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return (false);
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next)
		first->next->prev = first;
	*head = second;
	return (true);
}

void	sa(t_stack_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	if (swap(a) && swap(b))
		ft_printf("ss\n");
}
