/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:02:01 by lnierobi          #+#    #+#             */
/*   Updated: 2024/09/20 11:11:27 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	if (n < 0)
	{
		n = n * -1;
	}
	return (count);
}

static size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

static char	*ft_strdup(const char *s1)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new)
		return (NULL);
	while (*s1)
		new[i++] = *s1++;
	new[i] = '\0';
	return (new);
}

static char	*ft_itoa(int n)
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
		return (NULL);
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

int	print_int(long long n)
{
	char	*isstring;
	int		count;

	count = 0;
	isstring = ft_itoa(n);
	if (!isstring)
		return (-1);
	count = print_str(isstring);
	free(isstring);
	return (count);
}
