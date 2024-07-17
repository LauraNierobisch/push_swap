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


int is_number(const char *str)
{
	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return(0);
		}
		str++;
	}
	return(1);
}

int numbers_only(char **argv)
{
	int i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			return(0);
		}
		i++;
	}
	return (1);
}

//ich muss hier strcmp noch schreiben damit ich das reinmachen kann ich glaub ich hab das von der picine noch iwo
int dupli_int(int argc, char **argv)
{
	int i;
	int j;

	i = 1;

	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}



int in_long_range(int argc, char *argv[])
{
	long num;
	num = ft_atol(str);
	int i = 1;
	while (i < argc)
{
	if (num < LONG_MIN || num > LONG_MAX)
{
	return (0);
}
	i++;
}
	return (1);
}

int error_checker_complete(int argc, char *argv[])
{
if (!numbers_only(argc, argv))
{
	ft_putstr_fd("Error: All arguments must be numbers.\n", 2);
		exit(EXIT_FAILURE);
}

if (!are_in_long_range(argc, argv))
{
		ft_putstr_fd("Error: All arguments must be within the range of a long integer.\n", 2);
		exit(EXIT_FAILURE);
}

if (!dupli_int(argc, argv))
{
		ft_putstr_fd("Error: no duplicated numbers! .\n", 2);
		exit(EXIT_FAILURE);
}
return(0);
}
