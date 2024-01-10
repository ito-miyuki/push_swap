/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:22:29 by mito              #+#    #+#             */
/*   Updated: 2024/01/10 16:47:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//delete this functions
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
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


    first.nbr = 1;
    second.nbr = 2;
	third.nbr = 3;

	first.prev = NULL;
    first.next = &second;
    second.prev = &first;
    second.next = &third;
    third.prev = &second;
    third.next = NULL;
	
	lst = &first;
	
    printf("↓before rotate↓\n");
    ftt_lstiter(lst);
    printf("↓after rotate↓\n");
	rra(&lst, false);
    ftt_lstiter(lst);
    return (0);
}