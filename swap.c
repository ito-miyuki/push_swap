/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/05 17:25:08 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next) //リストの先頭がNULLか次がない場合
		return ; //何もしないで終わる
	*head = (*head)->next;  // 今１番前にあるやつを次のやつにする
	(*head)->prev->prev = *head; //  旧先頭ノード（現(*head)->prevのprevを新しい先頭ノードに設定
	(*head)->prev->next = (*head)->next; // 旧先頭ノードのnextを新先頭ノードの次のノードに設定
	if ((*head)->next) // 新しい先頭ノードの次のノードが存在する場合
		(*head)->next->prev = (*head)->prev; //そのノードの prevを旧先頭ノードに設定
	(*head)->next = (*head)->prev; // 新しい先頭ノードの next ポインタを旧先頭ノードに設定
	(*head)->prev = NULL; // 新しい先頭ノードの prevを NULL に設定
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		printf("sa\n"); //replace it with ft_printf!!!!
        //ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if(!print)
		printf("sb\n"); // replace it with ft_printf!!!!
}

void	ss(t_stack_node **a, t_stack_node *b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
}

