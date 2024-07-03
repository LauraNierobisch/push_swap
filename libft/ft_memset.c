/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:46:33 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/12 15:37:00 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #define BUF_SIZE 20
// int main(void)
// {
//    char buffer[BUF_SIZE + 1];
//    char *string;

//    ft_memset(buffer, 0, sizeof(buffer));
//    string = (char *) memset(buffer,'A', 10);
//    printf("\nBuffer contents: %s\n", string);
//    ft_memset(buffer, 'B', 10);
//    printf("\nBuffer contents: %s\n", buffer);
// }
