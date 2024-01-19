/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:23:26 by mito              #+#    #+#             */
/*   Updated: 2024/01/19 16:23:45 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdio.h> // delete it if you don't need it! I put this for printf
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

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

void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*find_last(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);

//stack_init.c
void			init_stack_a(t_stack_node **a, char **argv);
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
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **a, t_stack_node **b, bool print);

// swap.c
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

// rotate.c
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);

// rev_rotate.c
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);

void	ftt_lstiter(t_stack_node *lst); // delete it
#endif
