/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:59:46 by lnierobi          #+#    #+#             */
/*   Updated: 2024/08/02 16:04:24 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	error_function(void)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	exit(EXIT_FAILURE);
// }

// int	is_number(const char *str)
// {
// 	if (*str == '-')
// 	{
// 		str++;
// 	}
// 	while (*str != '\0')
// 	{
// 		if (!isdigit(*str))
// 		{
// 			return (0);
// 		}
// 		str++;
// 	}
// 	return (1);
// }

// int	numbers_only(int argc, char **argv)
// {
// 	int	i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if (!is_number(argv[i]))
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	dupli_int(int argc, char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < argc)
// 	{
// 		j = i + 1;
// 		while (j < argc)
// 		{
// 			if (ft_strcmp(argv[i], argv[j]) == 0)
// 			{
// 				return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	in_long_range(int argc, char *argv[])
// {
// 	long	num;
// 	int		i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		num = ft_atol(argv[i]);
// 		// printf("num %ld\n", num);
// 		if (num < INT_MIN || num > INT_MAX)
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	error_checker_complete(int argc, char *argv[])
// {
// 	if (!numbers_only(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!in_long_range(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!dupli_int(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (0);
// }
// void	error_for_quotes(char *argv)
// {
// 	char **split;
// 	int i;
// 	int split_count;

// 	split_count = 0;
// 	i = 0;

// 	split = ft_split(argv, ' ');
// 	// if (!split)
// 	// 	exit(1);
// 	while (split[split_count] != NULL)
// 	{
// 		split_count++;
// 	}
// 	error_checker_complete(split_count, split);
// 	if (split)
// 	{
// 		while (split[i] != NULL)
// 		{
// 			free(split[i]);
// 			i++;
// 		}
// 		free(split);
// 	}
// }
// error stuff dann  splitten dann schauen ob die sortiert sind und dann sortieren
// zuerst checken ob die zahlen schon sortiert

#include "push_swap.h"

char	error_function(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

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
	int	i;
	i = 1;
	if (argc ==1)
	{
		i = 0;
	}

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
			// || (argv[i] == 0 && argv[j] == -0)
			// || (argv[i] == -0 && argv[j] == 0))
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
		// printf("num %ld\n", num);
		if (num < INT_MIN || num > INT_MAX)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
// neue function um -0 und 0 zu finden wenn beides vorhanden ist dann error
int	error_checker_complete(int argc, char *argv[])
{

	 if (!numbers_only(argc, argv))
	 {
	 	ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	 }
	if (!in_long_range(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!dupli_int(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if(zero_together(argc, argv))
 	{
 		ft_putstr_fd("Error\n", 2);
 		exit(EXIT_FAILURE);
 	}
	return (0);
}

int zero_together(int argc, char *argv[])
{
	int	i;

	i = 0;
	// if (argc ==1)
	// {
	// 	i = 0;
	// }
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-") == 0)
		{
			return (1);
		}
		if ((ft_strcmp(argv[i], "-0") == 0))
		{
			return (1);
		}
		if (ft_strcmp(argv[i], "") == 0)
		{
			return (1);
		}
		if (ft_strcmp(argv[i], "--") == 0)
		{
			return (1);
		}
		if (ft_strcmp(argv[i], "+") == 0)
		{
			return (1);
		}
		// if (ft_strcmp(argv[i], "  ") == 0)
		// {
		// 	return (1);
		// }


		i++;
	}
	return(0);
}

// int	ft_error_checker_complete(int argc, char *argv[])
// {
// 	if (!ft_numbers_only(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!in_long_range(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!dupli_int(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	if(zero_together(argc, argv))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	return (0);
// }
void	error_for_quotes(char *argv)
{
	printf("[[%s]]\n", argv);
	char	**split;
	int		i;
	int		split_count;

	split_count = 0;
	i = 0;
	split = ft_split(argv, ' ');
	// if (!split)
	// 	exit(1);
	while (split[split_count] != NULL)
	{
		split_count++;
	printf("[[%i]]\n", split_count);
	}
	// if (split_count == 1)
	// {
	// 	if (!in_long_range(1, split))
	// 	{
	// 		ft_putstr_fd("Error\n", 2);
	// 		exit(EXIT_FAILURE);
	// 	}
	// }
	if(split_count > 1)
		error_checker_complete(split_count, split);
	printf("[%i]\n", split_count);
	// if(split_count == 1)
	//ft_error_checker_complete(split_count, split);
	if (split)
	{
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
