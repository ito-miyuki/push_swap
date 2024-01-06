/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:47:41 by mito              #+#    #+#             */
/*   Updated: 2024/01/06 16:07:31 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ss(t_stack_node **a, t_stack_node *b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		printf("ss\n");
}
//////////////////////////////////////////
//for testing

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void append_node(t_stack_node **stack, int n)
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
		//↑最後に繋げたいから１番最後のやつを見つける（縦に考えたら１番上だよね？）
		last_node->next = node;
		node->prev = last_node;
	}
}

int main()
{
    t_stack_node *temp = NULL;
    t_stack_node **a = &temp;

    append_node(a, 5);
    append_node(a, 8);
    append_node(a, 9);

    printf("Before swap:\n");
    t_stack_node *current = *a;
    while (current != NULL) {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n\n");

    swap(a);

    printf("After swap:\n");
    current = *a;
    while (current != NULL) {
        printf("%d ", current->nbr);
        current = current->next;
    }
    printf("\n");

    // メモリ解放などの後処理

    return 0;
}