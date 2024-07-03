/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:10:39 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/14 11:21:36 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	wholesize;
	void	*ptr;

	wholesize = count * size;
	ptr = malloc(wholesize);
	if (ptr != NULL)
	{
		ft_memset(ptr, 0, wholesize);
	}
	return (ptr);
}
