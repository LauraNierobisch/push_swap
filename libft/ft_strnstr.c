/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:16:24 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/14 13:06:56 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
	{
		return ((char *)&haystack[i]);
	}
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		if (needle[j] == haystack[i])
		{
			while (haystack[i + j] == needle[j] && needle[j] != '\0' && i
				+ j < len)
				j++;
			if (needle[j] == '\0')
			{
				return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (NULL);
}
