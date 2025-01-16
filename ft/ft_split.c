/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:41:30 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/17 15:13:16 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	counter(char const *s, char c)
{
	int	count;
	int	contain;

	contain = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			contain = 0;
		else if (!contain)
		{
			contain = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_word(const char *s, char c)
{
	const char	*start;
	char		*word;
	int			i;

	start = s;
	while (*s && *s != c)
		s++;
	word = malloc(sizeof (char) * (s - start + 1));
	if (!word)
		return (00);
	i = 0;
	while (start < s)
	{
		word[i++] = *start++;
	}
	word[i] = '\0';
	return (word);
}

static int	interate_words(int count, char **array, const char	*s, char c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		array[i] = get_word(s, c);
		if (!array[i])
		{
			return (00);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**array;

	if (!s)
		return (00);
	count = counter(s, c);
	array = malloc(sizeof (char *) * (count + 1));
	if (!array)
		return (00);
	if (!interate_words(count, &*array, s, c))
		return (00);
	array[count] = 00;
	return (array);
}
