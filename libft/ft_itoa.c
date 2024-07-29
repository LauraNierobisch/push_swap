/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:48:15 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/29 18:46:24 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_digits(int n)
{
	int	count;
	// int	sign;

	count = 0;
	// sign = 1;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	// sign = 1;
	if (n < 0)
	{
		// sign = -1;
		n = n * -1;
	}
	return (count);
}

// static	char	*edge_cases(int n)
// {
// 	if (n == 0)
// 	{
// 		return (ft_strdup("0"));
// 	}
// 	if (n == -32768)
// 	{
// 		return (ft_strdup("-32768"));
// 	}
// 	return (0);
// }

char	*ft_itoa(int n)
{
	int		sign;
	int		digits;
	char	*str;
	int		i;

	sign = 1;
	digits = ft_count_digits(n);
	if (n < 0)
		sign = -1;
	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (0);
	i = digits - 1;
	while (n != 0)
	{
		str[i--] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	str[digits] = '\0';
	return (str);
}

// int	main(void)
// {
// 	int	n;

// 	n = 0;
// 	printf("%s", ft_itoa(n));
// }
