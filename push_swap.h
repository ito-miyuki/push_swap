/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:23:26 by mito              #+#    #+#             */
/*   Updated: 2024/02/01 17:47:24 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

typedef struct s_stack_node
{
	int						nbr;
	int						index;
	int						push_cost;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*target_node;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

void				sort_three(t_stack_node **a);

t_stack_node		*find_last(t_stack_node *stack);
void				set_cheapest(t_stack_node *stack);

void				init_stack_a(t_stack_node **a, char **argv, int sp);
t_stack_node		*get_cheapest(t_stack_node *stack);
void				prep_for_push(t_stack_node **stack, t_stack_node *top_node,
						char stack_name);

void				sort_stacks(t_stack_node **a, t_stack_node **b);

void				init_nodes_b(t_stack_node *a, t_stack_node *b);

int					stack_len(t_stack_node *stack);
bool				stack_sorted(t_stack_node *stack);
t_stack_node		*find_last(t_stack_node *stack);
t_stack_node		*find_min(t_stack_node *stack);
t_stack_node		*find_max(t_stack_node *stack);

void				current_index(t_stack_node *stack);
void				set_cheapest(t_stack_node *stack);
void				init_nodes_a(t_stack_node *a, t_stack_node *b);

void				pa(t_stack_node **a, t_stack_node **b);
void				pb(t_stack_node **b, t_stack_node **a);

void				sa(t_stack_node **a);
void				sb(t_stack_node **b);
void				ss(t_stack_node **a, t_stack_node **b);

void				ra(t_stack_node **a);
void				rb(t_stack_node **b);
void				rr(t_stack_node **a, t_stack_node **b);

void				rra(t_stack_node **a);
void				rrb(t_stack_node **b);
void				rrr(t_stack_node **a, t_stack_node **b);

int					error_syntax(char *str_n);
int					error_duplicate(t_stack_node *a, int n);
void				free_errors(t_stack_node **a, char **array, int sp);
void				free_sp_array(char **array);
void				free_stack(t_stack_node **stack);

void				min_on_top(t_stack_node **a);

#endif
