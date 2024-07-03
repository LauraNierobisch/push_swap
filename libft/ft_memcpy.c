/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:57:14 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/22 18:57:25 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*c_dst;
	const unsigned char	*c_src;

	if (!dst && !src)
		return (NULL);
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #define BUF_SIZE 20

// int	main(void)
// {
// 	char	src[] = "NULL";
// 	char	dest[BUF_SIZE];

// 	ft_memcpy(dest, src, sizeof(src));
// 	printf("Copied string: %s\n", dest);
// 	return (0);
// }
