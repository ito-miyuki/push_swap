/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/25 11:48:37 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static void	swap(t_stack_node **head)
{
	t_stack_node *first;
	t_stack_node *second;
	//リストの中身が一つしかないときは？
	if (!*head || !(*head)->next) //リストの先頭がNULLか次がない場合
		return ; //何もしないで終わる
	first = *head; //firstがリストの最初を指す
	second = (*head)->next; //secondがその次をさす
	
	// 1, 2, 3というリストがあったとして、1がfirst、2がsecond
	first->next = second->next; //1の次が3になるようにする
	first->prev = second; //1の前が2になるようにする
	second->prev = NULL; //２の前がNULL これで２が先頭になる
	second->next = first; //２の次が１になるようにする

	if (first->next) //もし１の次がヌルじゃなかったら
		first->next->prev = first; //
	
	*head = second;
}

*/

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
