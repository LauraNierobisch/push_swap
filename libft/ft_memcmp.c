/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:44:34 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/13 19:20:45 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ms1;
	const unsigned char	*ms2;
	size_t				i;

	ms1 = (const unsigned char *)s1;
	ms2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ms1[i] != ms2[i])
		{
			return (ms1[i] - ms2[i]);
		}
		i++;
	}
	return (0);
}
