/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:23:26 by mito              #+#    #+#             */
/*   Updated: 2024/01/29 13:18:38 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h> // delete it if you don't need it! I put this for printf
# include <stdlib.h> // for malloc?

# include "libft.h"

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;


//sort_three.c
void				sort_three(t_stack_node **a);

t_stack_node	*find_last(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);

//stack_init.c
void			init_stack_a(t_stack_node **a, char **argv, int sp);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

//sort_stacks.c
void	sort_stacks(t_stack_node **a, t_stack_node **b);

// init_b_to_a
void    init_nodes_b(t_stack_node *a, t_stack_node *b);

// stack_utils.c
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);

// init_a_to_b
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);

// push.c
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

// swap.c
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

// rotate.c
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

// rev_rotate.c
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// handle_errors.c
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void    		free_errors(t_stack_node **a, char **array, int sp);
void			free_sp_array(char **array);
void    		free_stack(t_stack_node **stack);

//delete this function
void			ftt_lstiter(t_stack_node *lst); // delete it
#endif
