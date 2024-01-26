/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:53:35 by mito              #+#    #+#             */
/*   Updated: 2024/01/26 17:09:47 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//delete this ftt_lstiter function
void	ftt_lstiter(t_stack_node *lst)
{
	while (lst)
	{
		printf("%d\n", lst->nbr);
		lst = lst->next;
	}
}

int main(int argc, char **argv)
{	

	t_stack_node	*a; 
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		init_stack_a(&a, ft_split(argv[1], ' '));
	if (argc > 2)
		init_stack_a(&a, argv + 1); //a.outをスキップする
	if (!stack_sorted(a)) //もうすでに順番通りか確認
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	//ft_printf("**this is the result**\n");
	//ftt_lstiter(a);
	free_stack(&a);
	return (0);
}