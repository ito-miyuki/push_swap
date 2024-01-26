/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:24:40 by mito              #+#    #+#             */
/*   Updated: 2024/01/26 16:12:37 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node) //移動したいやつとそのターゲットのどっちかが先頭に来るまで
		rr(a, b);
	current_index(*a);
	current_index(*b);
}
static void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)	
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node; //prepしてからrotate bothを行わないのはなぜ？効率的じゃなくない？

	cheapest_node = get_cheapest(*a); //Aスタックの中にある一番安いものを設定
	if (cheapest_node->above_median && cheapest_node->target_node->above_median) //aもbも半分より上なら
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) //aもbも半分より下なら
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');//pushしたいものが一番上にあるかチェック
	prep_for_push(b, cheapest_node->target_node, 'b'); //pushしたいもののターゲットが一番上にあるかチェック
	pb(b, a);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target_node, 'a'); //pushしたいものが一番上にあるかチェック
	pa(a, b);
}

static void	min_on_top(t_stack_node **a) //一番小さい数字をいちばん上に持ってくる
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;
	len_a = stack_len(*a);
	
	if (len_a-- > 3 && !stack_sorted(*a)) //スタック内を３つにするため
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);  
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
