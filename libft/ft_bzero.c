/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:34:51 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/12 15:18:18 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] != '\0')
		{
			ptr[i] = '\0';
		}
		i++;
	}
}

// #include <stdio.h>
// #define BUF_SIZE 20

// int main(void) {
//     char buffer[BUF_SIZE];

//    bzero(buffer, sizeof(buffer));

//     printf("Buffer contents after ft_bzero: %s\n", buffer);

//     return (0);
// }
