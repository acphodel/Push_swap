/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:47:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:47:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r(t_stack *stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (stack && stack->top && stack->top->next)
	{
		first_node = stack->top;
		last_node = first_node;
		stack->top = stack->top->next;
		while (last_node->next)
			last_node = last_node->next;
		first_node->next = NULL;
		last_node->next = first_node;
	}
}

void	ra(t_stack *stack_a)
{
	r(stack_a);
	print_string("ra");
}

void	rb(t_stack *stack_b)
{
	r(stack_b);
	print_string("rb");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	r(stack_a);
	r(stack_b);
	print_string("rr");
}
