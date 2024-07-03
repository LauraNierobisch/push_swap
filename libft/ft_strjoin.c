/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:06:40 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/18 11:28:21 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		a;
	int		b;

	a = 0;
	b = 0;
	output = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!output)
		return (NULL);
	while (s1[a])
		output[b++] = s1[a++];
	a = 0;
	while (s2[a])
		output[b++] = s2[a++];
	output[b] = '\0';
	return (output);
}
