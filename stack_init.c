/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:14:24 by mito              #+#    #+#             */
/*   Updated: 2024/01/06 16:42:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack)) //stackはa、aはさっきNULLにしたよね！だから最初はここに来る
	{
		*stack = node;
		node->prev = NULL;
	}
	else //２回目のループ以降、aはもうNULLじゃないからここに来る
	{
		last_node = find_last(*stack); 
		//↑最後に繋げたいから１番最後のやつを見つける（縦に考えたら１番上だよね？）
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	//I need to add error handlings: duplicated nums, overflow, syntax error
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		n = ft_atoi(argv[i]); // argv は charとして扱われるから数字に変えないと
		append_node(a, (int)n);
		i++;
	}
}
