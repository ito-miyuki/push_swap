/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/29 14:12:29 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*head || !(*head)->next)
		return ;
	first = *head; //firstがリストの最初を指す
	second = (*head)->next; //secondがその次をさす
	// 1, 2, 3というリストがあったとして、1がfirst、2がsecond
	first->next = second->next; //1の次が3になるようにする
	first->prev = second; //1の前が2になるようにする
	second->prev = NULL; //２の前がNULL これで２が先頭になる
	second->next = first; //２の次が１になるようにする
	if (first->next) //もし１の次がヌルじゃなかったら
		first->next->prev = first;
	*head = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
