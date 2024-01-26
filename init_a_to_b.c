/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:24:04 by mito              #+#    #+#             */
/*   Updated: 2024/01/23 14:04:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int median;

	i = 0;
	if (!stack) //stackが空じゃないか確認する
		return ;
	median = stack_len(stack) / 2;
	while (stack) //全部のノードをチェック
	{
		stack->index = i; //今チェックしてるノードのインデックス
		if (i <= median) //i < median じゃなくて？真ん中の数字ならraもrraでも同じってことか
			stack->above_median = true;
		else
			stack->above_median = false; 
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) // aのターゲットノードを探す
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long	best_match;

	while(a) //aにノードがある間
	{
		best_match = LONG_MIN; //これがデフォルト
		current_b = b;
		while (current_b)
		{
			//ターゲットは一番近い小さい数字、それが存在しなければ一番大きいもの
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match == LONG_MIN) //この時点で初期のベストマッチが変わってないってことは見つからなかったってこと
			a->target_node = find_max(b); //だから一番大きいものに設定する
		else
			a->target_node = target_node; //ベストマッチがあったならそれで行く
		a = a->next; //次のノードに移動してターゲットを探す
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index; //aのコストはインデックスをデフォにする
		if (!(a->above_median)) //真ん中より下なら
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median) //真ん中より上なら
			a->push_cost += a->target_node->index; // I wrote wongly :a->target_node += a->target_node->index;
		else //aとbを踏まえての最終コスト計算
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	//ターゲットがわかったらどれが一番安く動かせるか計算
	//全部のpush costを比べて、現在のcheapest_valueよりも安いならそれに入れ替える

	long	cheapest_value;
	t_stack_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX; // ひとまずデカい数字にしておく
	while (stack) //全部のstackをひとつづ見ていく
	{
		if (stack->push_cost < cheapest_value) //今のcheapest_valuの方がこのpush costより安いなら
		{
			cheapest_value = stack->push_cost; //cheapest valueを更新
			cheapest_node = stack; //cheapest nodeに設定
		}
		stack = stack->next; //次のやつを比べる
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

