/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:05:39 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/12 12:26:53 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	unsigned long	ptrchange;
	int				count;

	count = 0;
	if (ptr == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	ptrchange = (unsigned long)ptr;
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	count += hex_low(ptrchange, 16);
	return (count);
}
