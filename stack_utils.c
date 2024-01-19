/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:11:18 by mito              #+#    #+#             */
/*   Updated: 2024/01/18 11:51:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;
	
	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long	min_num;
	t_stack_node *min_node;

	min_num = LONG_MAX;
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		if (stack->nbr < min_num)
		{
			min_num = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
t_stack_node	*find_max(t_stack_node *stack)
{
	long	max_num;
	t_stack_node *max_node;

	if (!stack)
		return (NULL);
	max_num = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max_num)
		{
			max_num = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/*
 #include <stdio.h>

// // FOR TESTING, DELETE IT
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
	t_stack_node    *lst;
    t_stack_node    first;
    t_stack_node    second;
	t_stack_node	third;
	t_stack_node	fourth;

    first.nbr = 9;
    second.nbr = 4;
	third.nbr = 5;
	fourth.nbr = 6;

	first.prev = NULL;
    first.next = &second;
    second.prev = &first;
    second.next = &third;
    third.prev = &second;
	third.next = &fourth;
	fourth.prev = &third;
    fourth.next = NULL;

	lst = &first;
	
//FIND_MAX/LAST TEST
t_stack_node	*max;
max = find_max(lst);
printf("↓list↓\n");
ftt_lstiter(lst);
printf("↓Max node↓\n");
printf("%d\n", max->nbr);
return (0);

// //FIND_MIN TEST
// t_stack_node	*min;
// min = find_min(lst);
// printf("↓list↓\n");
// ftt_lstiter(lst);
// printf("↓Min node↓\n");
// printf("%d\n", min->nbr);
// return (0);

// 	// STACK_SORTED TEST
// if (stack_sorted(lst) == false)
// 	printf("False");
// else if (stack_sorted(lst) == true)
// 	printf("True");

// 	//STACK_LEN TEST
// 	t_stack_node *list2;
// 	list2 = NULL;
	
// 	int length = stack_len(lst);
// 	int length2 = stack_len(list2);
	
// 	printf("%d\n", length2);
// 
//
}
*/