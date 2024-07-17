/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:59:46 by lnierobi          #+#    #+#             */
/*   Updated: 2024/07/17 11:47:01 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	error_function(void)
{
	ft_putstr_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int range_int (char **argv)
{
	long num;
	int sign;

	num = 0;
	sign = 1;

	if (*argv == '\0')
	{
		error_function();
	}
	if (*argv == '-')
	{
		sign = -1;
		argv ++;
	}
	if (*argv == '+')

}

int dupli_int(char **argv)
{
	int i;

}

int numbers_only(char **argv)
{

}