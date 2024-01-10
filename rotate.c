/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:27:43 by mito              #+#    #+#             */
/*   Updated: 2024/01/10 15:02:17 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // delete it!!

//delete this functions
t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
//////////////

static void	rotate(t_stack_node **stack)
{
	t_stack_node *last_node;
	
	if (!stack ||  !(*stack)->next) //一つしかnodeがないなら回転する必要なし
		return ;
	last_node = find_last(*stack); //最後のノードを見つけて記憶
	last_node->next = *stack;
	*stack = (*stack)->next; //現在の先頭ノードを次のノードに更新
	(*stack)->prev = NULL; //先頭だから
	//↓元の先頭ノードをリストの最後に移動
	last_node->next->prev = last_node; //最後のノードの次のノード（元の先頭）のprevを最後のノードに設定
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		printf("ra\n"); //replace it with ft_printf!!!!
		// ft_printf("ra\n");
}
void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		printf("ra\n"); //replace it with ft_printf!!!!
		// ft_printf("rb\n");
}

void	rr(t_stack_node **a,t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		printf("rr\n"); //replace it with ft_printf!!!!
		// ft_printf("rr\n");
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
	t_stack_node    *lst;
    t_stack_node    first;
    t_stack_node    second;

    first.nbr = 1;
    second.nbr = 2;
    second.next = NULL;
    first.next = &second;
    lst = &first;

    printf("↓before rotate↓\n");
    ftt_lstiter(lst);
	ra(&lst, false);
    printf("↓after rotate↓\n");
    ftt_lstiter(lst);
    return (0);
}

