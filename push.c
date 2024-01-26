/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:59 by mito              #+#    #+#             */
/*   Updated: 2024/01/25 11:47:07 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; //ここに一旦入れる

	if (*src == NULL) //(!*src) //srcがNULLなら。例えばa or b のリストの先頭が何もない時
		return ; //do nothing
	push_node = *src; //移動したいsrcをpush nodeに入れる
	*src = (*src)->next; //srcが次を指すようにする
	if (*src) 
		(*src)->prev = NULL; //srcのprevがNULLを指すことで、それが新しい先頭になる（先頭だからNULLを指してないといけない）
	push_node->prev = NULL; // push_node をdstの先頭として追加する際に、そのノードがリストの始点であることを示すため
	if (*dst == NULL) //(!*dst) //dstがNULLなら
	{
		*dst = push_node; //もしdstが空なら、いま移動するものをdst先頭nodeにする
		push_node->next = NULL; //次がNULLを指すようにする
	}
	else // もしdstが空じゃなかったら　つまりもう何回かpushしたならここに来るはず
	{
		push_node->next = *dst; //いま移動するものの次を現在のdstの先頭につなげる
		push_node->next->prev = push_node; //二個目になったdstのprevを新しく入ってきた先頭とつなげる
		*dst = push_node; //dstを更新
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");
}
void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a); // i wrote wrongly push(b, a)
	ft_printf("pb\n");
}
