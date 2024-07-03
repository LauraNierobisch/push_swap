/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:39:58 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/13 15:33:53 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	i;
	size_t	j;
	size_t	d;

	i = 0;
	while (dst[i] && i < dstsize)
	{
		i++;
	}
	d = i;
	j = 0;
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (d < dstsize)
		dst[i] = '\0';
	return (d + ft_strlen(src));
}
