/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:47:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:47:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_smallest_position(t_stack *stack)
{
	return (get_position(stack, 0));
}

void	four_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*fourth;

	if (sorted(stack_a))
		return ;
	first = stack_a-> top;
	second = first-> next;
	third = second-> next;
	fourth = third-> next;
	if (second-> value == 0)
		sa(stack_a);
	else if (fourth-> value == 0)
		rra(stack_a);
	else if (third-> value == 0)
	{
		ra(stack_a);
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	three_sort(stack_a);
	pa(stack_a, stack_b);
}

void	five_sort(struct s_stack *stack_a, struct s_stack *stack_b)
{
	int		p;

	if (sorted(stack_a))
		return ;
	p = get_smallest_position(stack_a);
	while (stack_a->top->value != 0)
	{
		if (p < 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	while (stack_a->top->value != 1)
	{
		if (p < 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	three_sort(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sorter(struct s_stack *stack_a, struct s_stack *stack_b, int size)
{
	if (size < 2)
		return ;
	if (size == 2)
		two_sort(stack_a);
	else if (size == 3)
		three_sort(stack_a);
	else if (size == 4)
		four_sort(stack_a, stack_b);
	else if (size == 5)
		five_sort(stack_a, stack_b);
	else if (size <= 20)
		butterfly(stack_a, stack_b, size, 3);
	else if (size <= 50)
		butterfly(stack_a, stack_b, size, 10);
	else if (size <= 100)
		butterfly(stack_a, stack_b, size, 15);
	else
		butterfly(stack_a, stack_b, size, 30);
}
