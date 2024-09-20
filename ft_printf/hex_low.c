/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_low.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:52:55 by lnierobi          #+#    #+#             */
/*   Updated: 2024/09/20 11:12:07 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extra_temp(unsigned long n, int base, int *count)
{
	int	temp;

	temp = hex_low(n, base);
	if (temp == -1)
		return (-1);
	else
	{
		*count += temp;
		return (0);
	}
}

int	hex_low(unsigned long n, int base)
{
	const char	letters[] = "0123456789abcdef";
	int			count;
	char		print;

	count = 0;
	print = letters[n % base];
	n = n / base;
	if (n > 0)
	{
		if (extra_temp(n, base, &count) == -1)
			return (-1);
	}
	if (write(1, &print, 1) == -1)
		return (-1);
	count++;
	return (count);
}
