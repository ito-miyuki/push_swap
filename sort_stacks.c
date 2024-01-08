/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:24:40 by mito              #+#    #+#             */
/*   Updated: 2024/01/08 12:36:49 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a)) 
		pb(b, a, false); 
	if (len_a-- > 3 && !stack_sorted(*a)) 
		pb(b, a, false); 
	/* 下の書き方ではダメ？
	if (len_a > 3 && !stack_sorted(*a)) 
	{
		pb(b, a, false);
		len_a--;
	}
	*/
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b); //not implemented yet
		move_a_to_b(a, b); //not implemented yet
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b); //not implemented yet
		move_b_to_a(a, b); //not implemented yet
	}
	current_index(*a); //not implemented yet
	min_on_top(a); //not implemented yet
}

