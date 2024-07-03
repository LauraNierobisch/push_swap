/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:10:01 by lnierobi          #+#    #+#             */
/*   Updated: 2024/04/03 11:22:55 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*from;
	char	*to;
	size_t	i;

	from = (char *)src;
	to = (char *)dst;
	if (from == to || len == 0)
		return (dst);
	if (to > from && (to - len) <= from)
	{
		i = len + 1;
		while (--i > 0)
			to[i - 1] = from[i - 1];
	}
	else
	{
		i = -1;
		while (++i < len)
			to[i] = from[i];
	}
	return (dst);
}

// int main ()
//  {
//    char dest[] = "oldstring";
//    const char src[]  = "newstring";

//    printf("Before memmove dest = %s, src = %s\n", dest, src);
//    ft_memmove(dest, src, 9);
//    printf("After memmove dest = %s, src = %s\n", dest, src);

//    return(0);
// }
