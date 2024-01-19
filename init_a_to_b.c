/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:24:04 by mito              #+#    #+#             */
/*   Updated: 2024/01/19 15:26:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
{
	int	i;
	int median;

	i = 0;
	printf("-inside current index function\n");
	if (!stack) //stackが空じゃないか確認する
	{
		printf("-stack is empty at current index func\n");
		return ;
	}
	printf("-stack is not empty\n");
	printf("stack len atm is %d\n", stack_len(stack));
	ftt_lstiter(stack); //delete this
	median = stack_len(stack) / 2;
	printf("-median index is %d\n", median);
	while (stack) //全部のノードをチェック
	{
		stack->index = i; //今チェックしてるノードのインデックス
		if (i <= median)
		{
			printf("-i <= median\n");
			stack->above_median = true; //falseじゃないの？
		}
		else
		{
			printf("-else\n");
			stack->above_median = false; //trueじゃないの？
		}
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b) // aのターゲットノードを探す
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long	best_match_index;

	printf("set_target_a\n");
	while(a) //aにノードがある間
	{
		printf("there is at least one node in a\n");
		best_match_index = LONG_MIN; //これがデフォルト
		current_b = b;
		while (current_b)
		{
			printf("loop untill there are some nodes in b\n");
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

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;
	
	printf("cost_analysis_a\n");

	len_a = stack_len(a);
	len_b = stack_len(b);
	printf("a\n");

	while (a)
	{
		a->push_cost = a->index;
		printf("b\n");

		if (!(a->above_median)) //真ん中より下なら
		{
			printf("f\n");

			a->push_cost = len_a - (a->index);

			printf("e\n");

		}
		printf("above_median: %d\n", a->target_node->above_median);

		printf("1\n");
		if (a->target_node->above_median) //真ん中より上なら
		{
			printf("d\n");
			a->target_node += a->target_node->index;
			

		}
		else
		{
			printf("g\n");
			a->push_cost += len_b - (a->target_node->index);

		}
		printf("c\n");

		a = a->next;

	}
	printf("end\n");

}

void	set_cheapest(t_stack_node *stack)
{
	//ターゲットがわかったらどれが一番安く動かせるか計算
	//全部のpush costを比べて、現在のcheapest_valueよりも安いならそれに入れ替える
	printf("set_cheapest\n");

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
	cheapest_node->cheapest = true; //ここでtrueにするのはなぜ？どこで使うの？
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	printf("-you're in init_nodes_a func\n");
	printf("a nbr is %d\n", a->nbr);
	printf("b nbr is %d\n", b->nbr);
	current_index(a);
	current_index(b); // bはemptyらしい
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
