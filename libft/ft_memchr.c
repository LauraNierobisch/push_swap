/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:14:09 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/13 18:36:38 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss = (const unsigned char *)s;
	unsigned char		cc;
	size_t				i;

	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ss[i] == cc)
		{
			return ((void *)&ss[i]);
		}
		i++;
	}
	return (NULL);
}
