/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:14:24 by mito              #+#    #+#             */
/*   Updated: 2024/01/26 11:53:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long ft_atol(const char *str)
{
	long long	res;
	int			negative;

	res = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1; // negative = -1 にしてもいい？
		str++;
	}
	while (*str >= 48 && *str <= 57) //ここでft_digit使おうか？
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)res * negative);
}
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
	if (!(*stack)) // if(*stack == NULL) stackはa、aはさっきNULLにしたよね！だから最初はここに来る
	{
		*stack = node;
		node->prev = NULL;
	}
	else //２回目のループ以降、aはもうNULLじゃないからここに来る
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char **num_input)
{
	long	n;
	int		i;

	i = 0;
	while (num_input[i])
	{
		n = ft_atol(num_input[i]);
		if (n > INT_MAX || n < INT_MIN)
			free(num_input);
		append_node(a, (int)n); // if there's no error, 
		i++;
	}
}

t_stack_node *get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	//移動するやつを上に持っていきたい
	while (*stack != top_node) //今は上にないなら（もう上にあるなら必要ないから）
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
