/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:16:07 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/11 15:28:50 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_decimal(unsigned int n, int base)
{
	const char	letters[] = "0123456789";
	int			count;
	char		print;
	int			temp;

	count = 0;
	print = letters[n % base];
	n = n / base;
	if (n > 0)
	{
		temp = unsigned_decimal(n, base);
		if (temp == -1)
			return (-1);
		else
			count += temp;
	}
	if (write(1, &print, 1) == -1)
		return (-1);
	return (count + 1);
}
// #include <stdio.h>

// int	main(void)
// {
// 	printf("%u\n", -5);
// 	unsigned_decimal(6, 10);
// 	return (0);
// }
// int i:

// i = unsigned_decimal(1235645, 16);
// i = 0;
