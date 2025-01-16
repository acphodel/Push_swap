/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:41:28 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:41:28 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *nums, int array_size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < (array_size - 1))
	{
		j = -1;
		while (++j < array_size - 1 - i)
		{
			if (nums[j] > nums[j + 1])
			{
				temp = nums[j + 1];
				nums[j + 1] = nums[j];
				nums[j] = temp;
			}
		}
	}
}

bool	sorted(struct s_stack *stack)
{
	struct s_node	*head;

	head = stack->top;
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	two_sort(struct s_stack *stack_a)
{
	if (stack_a->top->value)
		ra(stack_a);
}

void	three_sort(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
	else if (first < second && second > third)
		sa(stack);
}
