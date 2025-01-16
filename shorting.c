/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:17:30 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/17 15:13:03 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_there_any_number(char *chars)
{
	int	i;

	i = -1;
	while (chars[++i])
	{
		if (chars[i] >= '0' && chars[i] <= '9')
			return (1);
	}
	return (0);
}

char	*shorting_one(char	*input, char	*temp)
{
	if (ft_strcmp(temp, ""))
		free(temp);
	temp = input;
	input = ft_strjoin(input, " ");
	free(temp);
	return (input);
}

int	shorting_two(char *argv_i)
{
	if (!is_there_any_number(argv_i))
	{
		print_message("Error");
		return (1);
	}
	return (0);
}
