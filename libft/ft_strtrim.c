/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:39:27 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/20 11:41:38 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*output;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
	{
		return (0);
	}
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	output = malloc((end - start + 1) * sizeof(char));
	if (!output)
		return (0);
	ft_strlcpy(output, s1 + start, end - start + 1);
	return (output);
}
