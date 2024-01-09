/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:23:26 by mito              #+#    #+#             */
/*   Updated: 2024/01/09 17:31:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int 	push_cost;
	bool	above_median;
	bool	cheapest;
	struct	s_stack_node *target_node;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
}	t_stack_node;

void			init_stack_a(t_stack_node **a, char **argv);
t_stack_node	*find_last(t_stack_node *stack);
void	set_cheapest(t_stack_node *stack);

#endif

