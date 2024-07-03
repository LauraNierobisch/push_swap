/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_up.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:04:33 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/12 12:35:34 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extra_temp(unsigned long n, int base, int *count)
{
	int	temp;

	temp = hex_up(n, base);
	if (temp == -1)
		return (-1);
	else
	{
		*count += temp;
		return (0);
	}
}

int	hex_up(long long n, int base)
{
	const char	letters[] = "0123456789ABCDEF";
	int			count;
	char		print;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
		count++;
	}
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
// int	main(void)
// {
// 	unsigned int	n;
// 	int				base;

// 	n = 74787;
// 	base = 16;
// 	hex_low(n, base);
// 	return (0);
// }
