/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:24:40 by mito              #+#    #+#             */
/*   Updated: 2024/01/20 18:03:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
static void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a )	
		rrr(a, b, false);
		current_index(*a);
		current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node; //prepしてからrotate bothを行わないのはなぜ？効率的じゃなくない？

	cheapest_node = get_cheapest(*a); //Aスタックの中にある一番安いものを設定
	printf("-cheapest node: %d", cheapest_node->nbr);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median) //aもbも半分より上なら
		rotate_both(a, b, cheapest_node); 
	if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median)) //aもbも半分より下なら
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');//pushしたいものが一番上にあるかチェック
	prep_for_push(a, cheapest_node->target_node, 'b'); //pushしたいものが一番上にあるかチェック
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **b, t_stack_node **a)
{
	prep_for_push(a, (*b)->target_node, 'a'); //pushしたいものが一番上にあるかチェック
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a) //一番小さい数字をいちばん上に持ってくる
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;
	printf("-yay, we got into sort stacks function!!\n");
	len_a = stack_len(*a);
	printf("-a's length is: %d\n", len_a);
	if (len_a-- > 3 && !stack_sorted(*a)) //スタック内を３つにするため
	{
		printf("-push the top node from a\n");
		pb(b, a, false);
	}
	if (len_a-- > 3 && !stack_sorted(*a))
	{
		printf("-push again the a top node from a\n");
		pb(b, a, false);
	}
	/* 下の書き方ではダメ？
	if (len_a > 3 && !stack_sorted(*a)) 
	{
		pb(b, a, false);
		len_a--;
	}
	*/
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		printf("-you're in sort_stacks while loop because there are still more than 3 nodes\n");
		if (*a == NULL) //(!(*a)) // delete it
			printf("-*a points NULL\n"); // delete it
		if (*b == NULL) //(!(*b)) // delete it
			printf("-*b points NULL\n"); // delete it
		if (*a != NULL) //(!(*a)) // delete it
			printf("-*a is not NULL\n"); // delete it
		if (*b != NULL) //(!(*b)) // delete it
			printf("-*b is not NULL\n");	// delete it
		init_nodes_a(*a, *b);
		printf("-init_nodes_a was excuted\n");
		move_a_to_b(a, b); 
		printf("-move_a_to_b was excuted\n");
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
