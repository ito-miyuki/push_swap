/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:22:48 by mito              #+#    #+#             */
/*   Updated: 2024/01/18 14:13:49 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include  <stdio.h>

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	// 一番でかいやつを一番下にもって行くための処理
	if (biggest_node == *a)
	{
		printf("condtion: biggest_node == *a\n"); // delete this
		ra(a, false);
	}
	else if ((*a)->next == biggest_node)
	{
		printf("condition: (*a)->next == biggest_node\n"); // delete this
		rra(a, false);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		printf("condition: (*a)->nbr > (*a)->next->nbr\n"); // delete this
		sa(a, false); 
	}
	printf("sort 3 complete\n"); // delete this
}

/*
// below here, it's only for testing, delete it before submitting
#include <stdio.h>
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

	i = 1; //これって１じゃないの？./a.out だけしたら０出力されるけど？でも１にしたらsort three 狂うわ
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

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		printf("rra\n"); //replace it with ft_printf!!!!
        //ft_printf("rra\n");
}
static void	swap(t_stack_node **head)
{
	t_stack_node *first;
	t_stack_node *second;
	
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
void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		printf("sa\n"); //replace it with ft_printf!!!!
        //ft_printf("sa\n");
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long	max_num;
	t_stack_node *max_node;

	max_num = LONG_MIN;
	if (!stack)
		return (NULL);
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
// // you can delete this as it's in above comment
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	printf("max num is %d\n", biggest_node->nbr); //テスト後消してOK
	// 一番でかいやつを一番下にもって行くための処理
	if (biggest_node == *a)
	{
		printf("biggest_node == *a\n"); // delete it
		ra(a, false);
	}
	else if ((*a)->next == biggest_node)
	{
		printf("biggest_node == *a\n"); // delete it
		rra(a, false);
	}
	if ((*a)->nbr > (*a)->next->nbr)
	{
		printf("biggest_node == *a\n"); // delete it
		sa(a, false);
	}
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

int main(int argc, char **argv)
{
	t_stack_node *a = NULL;
	init_stack_a(&a, argv);
	ftt_lstiter(a);
	printf("after sorting\n");
	sort_three(&a);
	ftt_lstiter(a);
}

*/