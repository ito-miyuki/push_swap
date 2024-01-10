/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:59 by mito              #+#    #+#             */
/*   Updated: 2024/01/10 16:34:36 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete it from here

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; //ここに一旦入れる

	if (!*src) //例えばa or b のリストの先頭が何もない時
		return ; //do nothing
	push_node = *src; //srcを一旦ここに入れる（移動のため）
	*src = (*src)->next; //srcが次を指すようにする
	if (*src) 
		(*src)->prev = NULL; //srcのprevがNULLを指すことで、それが先頭になる（先頭だからNULLを指してないといけない）
	push_node->prev = NULL; // push_node をdstの先頭として追加する際に、そのノードがリストの始点であることを示すため
	if (!*dst)
	{
		*dst = push_node; //もしdstが空なら、最初のnodeにする
		push_node->next = NULL; //次がNULLを指すようにする
	}
	else // もしdstが空じゃなかったら
	{
		push_node->next = *dst; //現在のdstの先頭に入れたいものをつなげる
		push_node->next->prev = push_node; //二個目になったdstのprevを新しく入ってきた先頭とつなげる
		*dst = push_node; //dstを更新
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		printf("pa\n"); //replace it with ft_printf!!!!
		//ft_printf("pa\n");
}
void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		printf("pb\n"); //replace it with ft_printf!!!!
		//ft_printf("pb\n");
}


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

// FOR TESTING, DELETE IT
int main()
{
	t_stack_node *list1;
	t_stack_node first;
	t_stack_node second;
	
	first.nbr = 5;
	second.nbr = 6;

	first.prev = NULL;
	first.next = &second;
	second.next = NULL;	
	list1 = &first;

	t_stack_node *list2;
	t_stack_node first2;
	t_stack_node second2;
	
	first2.nbr = 7;
	second2.nbr = 8;

	first2.prev = NULL;
	first2.next = &second2;
	second2.next = NULL;	
	list2 = &first2;

	printf("BEFORE\n");
	printf("List1\n");
	ftt_lstiter(list1);
	printf("List2\n");
	ftt_lstiter(list2);
	
	printf("AFTER\n");
	pa(&list1, &list2, true);
	printf("List1\n");
	ftt_lstiter(list1);
	printf("List2\n");
	ftt_lstiter(list2);
}