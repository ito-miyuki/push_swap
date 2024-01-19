/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/17 16:04:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> // delete it

static void	swap(t_stack_node **head)
{
	t_stack_node *first;
	t_stack_node *second;
	//リストの中身が一つしかないときは？
	if (!*head || !(*head)->next) //リストの先頭がNULLか次がない場合
		return ; //何もしないで終わる
	first = *head; //firstがリストの最初を指す
	second = (*head)->next; //secondがその次をさす
	
	// 1, 2, 3というリストがあったとして、1がfirst、2がsecond
	first->next = second->next; //1の次が3になるようにする
	first->prev = second; //1の前が2になるようにする
	second->prev = NULL; //２の前がNULL これで２が先頭になる
	second->next = first; //２の次が１になるようにする

	if (first->next) //もし１の次がヌルじゃなかったら
		first->next->prev = first; //
	
	*head = second;
}

/*
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next) //リストの先頭がNULLか次がない場合
		return ; //何もしないで終わる
	*head = (*head)->next;  // 今１番前にあるやつを次のやつにする
	(*head)->prev->prev = *head; //  旧先頭ノード（現(*head)->prevのprevを新しい先頭ノードに設定
	(*head)->prev->next = (*head)->next; // 旧先頭ノードのnextを新先頭ノードの次のノードに設定
	if ((*head)->next) // 新しい先頭ノードの次のノードが存在する場合
		(*head)->next->prev = (*head)->prev; //そのノードの prevを旧先頭ノードに設定
	(*head)->next = (*head)->prev; // 新しい先頭ノードの next ポインタを旧先頭ノードに設定
	(*head)->prev = NULL; // 新しい先頭ノードの prevを NULL に設定
}
*/

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		printf("sa\n"); //replace it with ft_printf!!!!
        //ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if(!print)
		printf("sb\n"); // replace it with ft_printf!!!!
		//ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
		// replace it with ft_printf!!!!
		//ft_printf("ss\n");
}
/*
//////////////////////////////////////////
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
	t_stack_node *list;
	t_stack_node first;
	t_stack_node second;
	t_stack_node third;

	first.nbr = 1;
	second.nbr = 2;
	third.nbr = 3;

	third.next = NULL;
	first.next = &second;
	second.next = &third;

	list = &first;

	printf("↓BEFORE↓\n");
    ftt_lstiter(list);
    printf("↓AFTER↓\n");
	sa(&list, true);
    ftt_lstiter(list);
    return (0);
}

*/