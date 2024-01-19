/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:14:24 by mito              #+#    #+#             */
/*   Updated: 2024/01/19 16:03:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for Printf, delete it from here
#include "push_swap.h"
#include "libft/libft.h"

// delete find_last func from here
// t_stack_node	*find_last(t_stack_node *stack)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next)
// 		stack = stack->next;
// 	return (stack);
// }

// delete find_max func from here
// t_stack_node	*find_max(t_stack_node *stack)
// {
// 	long	max_num;
// 	t_stack_node *max_node;

// 	max_num = LONG_MIN;
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next)
// 	{
// 		if (stack->nbr > max_num)
// 		{
// 			max_num = stack->nbr;
// 			max_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (max_node);
// }
///

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
	if (*stack == NULL) //stackはa、aはさっきNULLにしたよね！だから最初はここに来る
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

void	init_stack_a(t_stack_node **a, char **argv)
{
	long	n;
	int		i;

	i = 0; //これって１じゃないの？./a.out だけしたら０出力されるけど？
	while (argv[i])
	{
		//Aadd error handling: syntax error
		n = ft_atol(argv[i]); // argv は charとして扱われるから数字に変えないと
		//Add error handling: overflow
		//Add error handling: duplicated nums
		// if there's no error
		append_node(a, (int)n);
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

// this should be here but commentted out temporaly
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	//移動するやつを上に持っていきたい
	while (*stack != top_node) //今は上にないなら（もう上にあるなら必要ないから）
	{
		if (stack_name == 'a') 
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

//for testing append node

// void	ftt_lstiter(t_stack_node *lst)
// {
// 	//if (!lst || !f)
// 	//	return ;
// 	while (lst)
// 	{
// 		//f(lst->target_node);
// 		printf("%d\n", lst->nbr);
// 		lst = lst->next;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	t_stack_node	*lst;
// 	t_stack_node	first;
// 	t_stack_node	second;

// 	first.nbr = 1;
// 	second.nbr = 2;
// 	second.next = NULL;
// 	first.next = &second;
// 	lst = &first;

// 	printf("BEFORE APPEND\n");
// 	ftt_lstiter(&first);
	
// 	int i = 1;
// 	while (argv[i] != '\0')
// 	{
// 		append_node(&lst, atoi(&argv[i][0]));
// 		i++;
// 	}
// 	printf("AFTER APPEND\n");
// 	ftt_lstiter(&first);
	/*
	printf("↓before append_node↓\n");
	ftt_lstiter(&first);	
	append_node(&lst, );
	printf("↓after append_node↓\n");
	ftt_lstiter(&first);
	append_node(&lst, 8);
	printf("↓after append_node↓\n");
	ftt_lstiter(&first);
	append_node(&lst, 9);
	printf("↓after append_node↓\n");
	ftt_lstiter(&first);
	return (0);
	}
	*/


// for testing init_stack func
// void	ftt_lstiter(t_stack_node *lst)
// {
// 	//if (!lst || !f)
// 	//	return ;
// 	while (lst)
// 	{
// 		//f(lst->target_node);
// 		printf("%d\n", lst->nbr);
// 		lst = lst->next;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	t_stack_node *a = NULL;
// 	init_stack_a(&a, argv);
// 	ftt_lstiter(a);
// }