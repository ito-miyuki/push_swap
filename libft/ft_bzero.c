/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:12:17 by mito              #+#    #+#             */
/*   Updated: 2023/11/15 14:31:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*char_s;
	size_t	i;

	char_s = (char *)s;
	i = 0;
	while (i < n)
	{
		char_s[i] = 0;
		i++;
	}
}