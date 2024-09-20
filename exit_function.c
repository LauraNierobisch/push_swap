/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:59:46 by lnierobi          #+#    #+#             */
/*   Updated: 2024/09/20 12:15:46 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	if (*str == '-')
	{
		str++;
	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_numbers_only(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	numbers_only(int argc, char **argv)
{
	int		i;
	char	tracker;

	tracker = ' ';
	i = 1;
	if (argc == 1)
	{
		i = 0;
	}
	while (i < argc)
	{
		if (tracker == '-' && *argv[i] == '-')
			return (0);
		if (!is_number(argv[i]))
		{
			return (0);
		}
		tracker = *argv[i];
		i++;
	}
	return (1);
}

int	dupli_int(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			remove_leading_zeros(argv[i]);
			remove_leading_zeros(argv[j]);
			if (ft_strcmp(argv[i], argv[j]) == 0)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	in_long_range(int argc, char *argv[])
{
	long	num;
	int		i;

	i = 0;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	error_checker_complete(int argc, char *argv[])
{
	if (!numbers_only(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!in_long_range(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!dupli_int(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (zero_together(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	zero_together(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
			return (1);
		if (ft_strcmp(argv[i], "") == 0)
			return (1);
		if (ft_strcmp(argv[i], "--") == 0)
			return (1);
		if (ft_strcmp(argv[i], "+") == 0)
			return (1);
		if (ft_strcmp(argv[i], "  ") == 0)
			return (1);
		i++;
	}
	return (0);
}
