/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:24:04 by mito              #+#    #+#             */
/*   Updated: 2024/01/10 13:57:07 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) // aのターゲットノードを探す
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long	best_match_index;

	while(a) //aにノードがある間
	{
		best_match_index = LONG_MIN; //これがデフォルト
		current_b = b;
		while (current_b)
		{
			//ターゲットは一番近い小さい数字、それが存在しなければ一番大きいもの
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN) //この時点で初期のベストマッチが変わってないってことは見つからなかったってこと
			a->target_node = find_max(b); //だから一番大きいものに設定する
		else
			a->target_node = target_node; //ベストマッチがあったならそれで行く
		a = a->next; //次のノードに移動してターゲットを探す
	}
}

static void	cost_anlysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;
	
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median)) //真ん中より下なら
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median) //真ん中より上なら
			a->target_node += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	//ターゲットがわかったらどれが一番安く動かせるか計算
	long	cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;	
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

