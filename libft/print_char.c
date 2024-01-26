/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:11:32 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:37 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	if (count < 0)
		return (-1);
	else
		return (count);
}
