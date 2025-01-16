/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shorting2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:17:30 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/17 15:07:26 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numerical(char character)
{
	if (character < '0' || character > '9')
		return (0);
	return (1);
}

int	operations_checked(char *potentialNumber)
{
	int		i;
	char	before_operator;

	if (!potentialNumber)
		return (1);
	i = 0;
	before_operator = ' ';
	while (potentialNumber[i])
	{
		if (potentialNumber[i] == '-' || potentialNumber[i] == '+')
		{
			if (is_numerical(before_operator))
				return (0);
			else if (before_operator == '-' || before_operator == '+')
				return (0);
		}
		before_operator = potentialNumber[i];
		i++;
	}
	return (1);
}

int	is_possible_numerical(char *potentialNumber)
{
	int	i;

	if (!potentialNumber)
		return (00);
	i = 0;
	while (potentialNumber[i]
		&& (is_numerical(potentialNumber[i]) || potentialNumber[i] == ' '
			|| potentialNumber[i] == '-' || potentialNumber[i] == '+'))
		i++;
	if (!potentialNumber[i])
		return (1);
	return (0);
}

int	nums_and_check(char	*input)
{
	int	*nums;
	int	*left;
	int	i;

	left = NULL;
	nums = NULL;
	nums = num_array(input);
	if (nums == 00 || !is_possible_numerical(input)
		|| !operations_checked(input))
	{
		print_message("Error");
		return (1);
	}
	free(input);
	i = 0;
	while (nums[i] != 0 || nums[i + 1] != 0)
		i++;
	swapper(nums, i - 1, left);
	free(nums);
	return (0);
}
