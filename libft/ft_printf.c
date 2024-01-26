/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:45:33 by mito              #+#    #+#             */
/*   Updated: 2024/01/24 10:56:18 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			count += print_format(*(++str), ap);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += write(1, str, 1);
			if (count < 0)
				return (-1);
		}
		str++;
	}
	va_end(ap);
	return (count);
}
