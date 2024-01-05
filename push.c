/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:59 by mito              #+#    #+#             */
/*   Updated: 2024/01/05 17:26:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; //ここに一旦入れる

	if (!*src) //例えばa or b のリストの先頭が何もない時
		return ; //do nothing
	push_node = *src; //srcを一旦ここに入れる（移動のため）
	*src = (*src)->next; //srcが次を指すようにする
	if (*src) 
		(*src)->prev = NULL; //srcのprevがNULLを指すことで、それが先頭になる（先頭だからNULLを指してないといけない）
	push_node->prev = NULL; // push_node をdstの先頭として追加する際に、そのノードがリストの始点であることを示すため
	if (!*dst)
	{
		*dst = push_node; //もしdstが空なら、最初のnodeにする
		push_node->next = NULL; //次がNULLを指すようにする
	}
	else // もしdstが空じゃなかったら
	{
		push_node->next = *dst; //現在のdstの先頭に入れたいものをつなげる
		push_node->next->prev = push_node; //二個目になったdstのprevを新しく入ってきた先頭とつなげる
		*dst = push_node; //dstを更新
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		printf("pa\n"); //replace it with ft_printf!!!!
		//ft_printf("pa\n");
}
void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		printf("pb\n"); //replace it with ft_printf!!!!
		//ft_printf("pb\n");
}




