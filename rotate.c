/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:27:43 by mito              #+#    #+#             */
/*   Updated: 2024/01/25 11:48:02 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node *last_node;
	
	if (!*stack || !(*stack)->next) //一つしかnodeがないなら回転する必要なし
		return ;
	last_node = find_last(*stack); //最後のノードを見つけて記憶
	last_node->next = *stack;
	*stack = (*stack)->next; //現在の先頭ノードを次のノードに更新
	(*stack)->prev = NULL; //先頭だから
	//↓元の先頭ノードをリストの最後に移動
	last_node->next->prev = last_node; //最後のノードの次のノード（元の先頭）のprevを最後のノードに設定
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}
void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a,t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
