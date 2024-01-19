/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:53:59 by mito              #+#    #+#             */
/*   Updated: 2024/01/19 16:20:26 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //delete it from here

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node; //ここに一旦入れる

	printf("dst nbr is at the beginning %d\n", (*dst)->nbr);
	// if (*src == NULL)
	// 	printf("\n\n\n*src is NULL\n\n\n");
	// else
		printf("src nbr is at the beginning %d\n", (*src)->nbr);
	if (!*src) //例えばa or b のリストの先頭が何もない時
	{
		printf("src is empty in push function\n");
		return ; //do nothing
	}
	push_node = *src; //srcを一旦ここに入れる（移動のため）
	printf("push_node nbr is %d\n", push_node->nbr);
	*src = (*src)->next; //srcが次を指すようにする
	if (*src) 
		(*src)->prev = NULL; //srcのprevがNULLを指すことで、それが先頭になる（先頭だからNULLを指してないといけない）
	push_node->prev = NULL; // push_node をdstの先頭として追加する際に、そのノードがリストの始点であることを示すため
	if (!*dst)
	{
		*dst = push_node; //もしdstが空なら、最初のnodeにする
		printf("dst nbr is %d\n", (*dst)->nbr);
		push_node->next = NULL; //次がNULLを指すようにする
	}
	else // もしdstが空じゃなかったら
	{
		printf("dst is not empty in push function\n");
		push_node->next = *dst; //現在のdstの先頭に入れたいものをつなげる
		push_node->next->prev = push_node; //二個目になったdstのprevを新しく入ってきた先頭とつなげる
		*dst = push_node; //dstを更新
		printf("dst nbr is %d\n", (*dst)->nbr);
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



// FOR TESTING, DELETE IT

// void	ftt_lstiter(t_stack_node *lst)
// {
// 	if (!lst)
// 		return ;
// 	while (lst)
// 	{
// 		//f(lst->target_node);
// 		printf("%d\n", lst->nbr);
// 		lst = lst->next;
// 	}
// }


// int main()
// {
// 	t_stack_node *list1;
// 	t_stack_node first;
// 	t_stack_node second;

// 	first.nbr = 5;
// 	second.nbr = 6;

// 	first.prev = NULL;
// 	first.next = &second;
// 	second.next = NULL;	
// 	list1 = &first;

// 	t_stack_node *list2;
// 	list2 = NULL;
// 	t_stack_node first2;
// 	//t_stack_node second2;
	
// 	first2.nbr = 7;
// 	//second2.nbr = 8;

// 	first2.prev = NULL;
// 	first2.next = NULL;
// 	//first2.next = &second2;
// 	//second2.next = NULL;	
// 	list2 = &first2;

// 	printf("BEFORE\n");
// 	printf("List1\n");
// 	ftt_lstiter(list1);
// 	printf("List2\n");
// 	ftt_lstiter(list2);
	
// 	printf("AFTER\n");
// 	pb(&list1, &list2, true);
// 	printf("List1\n");
// 	ftt_lstiter(list1);
// 	printf("List2\n");
// 	ftt_lstiter(list2);
// }
