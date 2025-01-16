/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:47:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:47:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	transform_shortage(int *numi, int *repi, long temp)
{
	*numi = (int) temp;
	*repi = (int) temp;
}

int	*transform(char **strings, int *nums, int i)
{
	int		*rep;
	int		j;
	int		k;
	long	temp;

	rep = (int *)malloc(sizeof(int *) * (i + 2));
	j = 0;
	while (--i >= 0)
	{
		temp = long_atoi(strings[i]);
		k = 0;
		while (k < j)
			if (rep[k++] == temp)
				return (00);
		if (temp <= 2147483647 && temp >= -2147483648)
			transform_shortage(&nums[i], &rep[j++], temp);
		else
		{
			free(rep);
			return (00);
		}
	}
	free(rep);
	return (nums);
}

int	*num_array(char *input)
{
	int		*nums;
	char	**strings;
	int		i;

	i = 0;
	strings = ft_split(input, ' ');
	while (strings[i])
		i++;
	nums = (int *)malloc(sizeof(int *) * (i + 2));
	nums[i] = i;
	nums[i + 1] = 0;
	nums[i + 2] = 0;
	nums = transform(strings, nums, i);
	while (--i >= 0)
		free(strings[i]);
	free(strings);
	return (nums);
}

int	main(int argc, char **argv)
{
	char	*input;
	int		i;
	char	*temp;

	if (argc != 1)
	{
		input = "";
		i = 1;
		while (--argc)
		{
			if (shorting_two(argv[i]) == 1)
				return (1);
			temp = input;
			input = ft_strjoin(input, argv[i++]);
			input = shorting_one(input, temp);
		}
		if (nums_and_check(input) == 1)
			return (1);
		exit(0);
	}
	print_message("Error");
	exit(1);
}
