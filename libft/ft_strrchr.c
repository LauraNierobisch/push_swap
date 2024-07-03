/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:06:43 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/14 11:00:09 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	cc;
	int				i;

	i = ft_strlen(s);
	cc = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == cc)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	if (cc == 0)
		return ((char *)&s[i]);
	return (NULL);
}
