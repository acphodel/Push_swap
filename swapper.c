/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:21:52 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/17 15:52:55 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	*sort_numbers(int const *nums, int size)
{
	int	*sorted_nums;
	int	i;

	sorted_nums = (int *) malloc(sizeof (int) * (size + 2));
	i = -1;
	while (++i < size)
	{
		sorted_nums[i] = nums[i];
	}
	bubble_sort(sorted_nums, size);
	return (sorted_nums);
}

struct s_number	*init_structure(int *nums, int *sorted_nums, int size)
{
	struct s_number	*number;
	int				i;
	int				j;

	number = (struct s_number *) malloc(sizeof(struct s_number) * size);
	i = -1;
	while (++i < size)
	{
		number[i].value = nums[i];
		j = -1;
		while (++j < size)
		{
			if (sorted_nums[j] == nums[i])
			{
				number[i].place = j;
				j = size;
			}
		}
	}
	free(sorted_nums);
	return (number);
}

struct s_node	*create_node(void)
{
	struct s_node	*node;

	node = (struct s_node *)malloc(sizeof (struct s_node));
	if (!node)
	{
		return (00);
	}
	return (node);
}

struct s_node	*init_node(struct s_number *numbers, int size)
{
	struct s_node	*head;
	struct s_node	*tail;
	int				i;

	head = create_node();
	i = -1;
	tail = head;
	while (++i < size)
	{
		tail->value = numbers[i].place;
		if (i + 1 != size)
		{
			tail->next = create_node();
			tail = tail-> next;
		}
		else
			tail -> next = NULL;
	}
	free(numbers);
	return (head);
}

void	swapper(int *nums, int size, int *sorted_nums)
{
	struct s_number	*numbers;
	struct s_node	*head;
	struct s_node	*temp;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;

	sorted_nums = sort_numbers(nums, size);
	numbers = init_structure(nums, sorted_nums, size);
	head = init_node(numbers, size);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_a->top = head;
	stack_b->top = NULL;
	sorter(stack_a, stack_b, size);
	head = stack_a->top;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
	free(stack_a);
	free(stack_b);
}
