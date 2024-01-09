/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:14:24 by mito              #+#    #+#             */
/*   Updated: 2024/01/09 11:19:06 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for Printf, delete it from here
#include "push_swap.h"
#include "libft/libft.h"

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
	if (!(*stack)) //stackはa、aはさっきNULLにしたよね！だから最初はここに来る
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

	i = 0;
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

// for testing, delete it before submitting
void	ftt_lstiter(t_stack_node *lst)
{
	//if (!lst || !f)
	//	return ;
	while (lst)
	{
		//f(lst->target_node);
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

int main()
{
	t_stack_node	*lst;
	t_stack_node	first;
	t_stack_node	second;

	first.nbr = 1;
	second.nbr = 2;
	second.next = NULL;
	first.next = &second;
	lst = &first;

	printf("↓before append_node↓\n");
	ftt_lstiter(&first);	
	append_node(&lst, 7);
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