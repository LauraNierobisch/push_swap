/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:50:22 by lnierobi          #+#    #+#             */
/*   Updated: 2024/03/30 16:10:30 by lnierobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char c, char const *s)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (in_word == 1)
		{
			if (s[i] == c)
				in_word = 0;
		}
		else
		{
			if (s[i] != c)
			{
				count++;
				in_word = 1;
			}
		}
		i++;
	}
	return (count);
}

// int	main(void)
// {
// 	char		c;
// 	const char	*s = "";
// 	int			count;

// 	c = '_';
// 	count = ft_count_word(c, s);
// 	printf("output: %d", count);
// 	return (0);
// }

static char	*ft_copy(const char *s, char c)
{
	int		i;
	int		word_start;
	char	*word;

	i = 0;
	word_start = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word_start = i;
			while (s[i] && s[i] != c)
				i++;
			word = (char *)malloc(sizeof(char) * (i - word_start + 1));
			if (!word)
				return (0);
			ft_strlcpy(word, s + word_start, i - word_start + 1);
			return (word);
		}
		i++;
	}
	return (0);
}

static void	ft_free(char **word)
{
	int	i;

	if (word)
	{
		i = 0;
		while (word[i])
		{
			free(word[i]);
			i++;
		}
		free(word);
	}
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		word_count;

	word_count = 0;
	word = (char **)malloc(sizeof(char *) * (ft_count_word(c, s) + 1));
	if (!word)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			word[word_count++] = ft_copy(s, c);
			if (!word[word_count - 1])
			{
				ft_free(word);
				return (0);
			}
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	word[word_count] = NULL;
	return (word);
}
