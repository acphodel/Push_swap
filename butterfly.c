/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:28:28 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/17 15:45:31 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly(struct s_stack *stack_a, struct s_stack *stack_b,
		int size, int n)
{
	int	pointer;

	if (sorted(stack_a))
		return ;
	pointer = 0;
	while (pointer < size)
	{
		if (stack_a->top->value <= pointer)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			pointer ++;
		}
		else if (stack_a->top->value <= pointer + n)
		{
			pb(stack_a, stack_b);
			pointer ++;
		}
		else
			ra(stack_a);
	}
	send_back_to_a(stack_a, stack_b, size, n);
}

int	short_send_back(int position, struct s_stack *stack_b, int pointer)
{
	while (position != 0)
	{
		rrb(stack_b);
		position++;
		if (position > pointer)
			position = 0;
	}
	return (position);
}

void	send_back_to_a(struct s_stack *stack_a, struct s_stack *stack_b,
				int size, int n)
{
	int	pointer;
	int	position;

	pointer = size - 1;
	while (pointer >= 0)
	{
		position = get_position(stack_b, pointer);
		if (position > pointer - n)
			position = short_send_back(position, stack_b, pointer);
		else if (position <= n)
		{
			while (position != 0)
			{
				rb(stack_b);
				position--;
			}
		}
		if (position == 0)
			pa(stack_a, stack_b);
		pointer--;
	}
}

int	get_position(t_stack *stack, int value)
{
	int		p;
	t_node	*head;

	p = 0;
	head = stack->top;
	while (head && head->value != value)
	{
		head = head->next;
		p++;
	}
	return (p);
}
