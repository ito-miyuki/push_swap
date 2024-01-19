/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:22:29 by mito              #+#    #+#             */
/*   Updated: 2024/01/17 16:03:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


//delete this functions
// t_stack_node	*find_last(t_stack_node *stack)
// {
// 	if (!stack)
// 		return (NULL);
// 	while (stack->next)
// 		stack = stack->next;
// 	return (stack);
// }
/////////////////////

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node *last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		printf("rra\n"); //replace it with ft_printf!!!!
        //ft_printf("rra\n");
}
void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		printf("rrb\n"); //replace it with ft_printf!!!!
        //ft_printf("rrb\n");
}
void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		printf("rrr\n"); //replace it with ft_printf!!!!
        //ft_printf("rrb\n");
}

/*
// FOR TESTING, DELETE IT
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


    first.nbr = 1;
    second.nbr = 2;
	third.nbr = 3;
	fourth.nbr = 4;

	first.prev = NULL;
    first.next = &second;
    second.prev = &first;
    second.next = &third;
    third.prev = &second;
	third.next = &fourth;
	fourth.prev = &third;
    fourth.next = NULL;
	
	lst = &first;

	
	t_stack_node    *lst2;
    t_stack_node    first2;
    t_stack_node    second2;
	t_stack_node	third2;
	t_stack_node	fourth2;

    first2.nbr = 1;
    second2.nbr = 2;
	third2.nbr = 3;
	fourth2.nbr = 4;

	first2.prev = NULL;
    first2.next = &second2;
    second2.prev = &first2;
    second2.next = &third2;
    third2.prev = &second2;
	third2.next = &fourth2;
	fourth2.prev = &third2;
    fourth2.next = NULL;
	
	lst2 = &first2;
	
    printf("↓before rotate↓\n");
	printf("list1\n");
    ftt_lstiter(lst2);
	//printf("list2\n");
	//ftt_lstiter(lst2);
	printf("↓after rotate↓\n");
	rrb(&lst2, false);
	printf("list1\n");
    ftt_lstiter(lst2);
	//printf("list2\n");
	//ftt_lstiter(lst2);
    return (0);
}

*/