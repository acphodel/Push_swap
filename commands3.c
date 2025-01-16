/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:47:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:47:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rtr(t_stack *stack)
{
	t_node	*last_node;
	t_node	*second_last_node;

	if (stack && stack->top && stack->top->next)
	{
		last_node = stack->top;
		while (last_node->next)
		{
			second_last_node = last_node;
			last_node = last_node->next;
		}
		second_last_node->next = NULL;
		last_node->next = stack->top;
		stack->top = last_node;
	}
}

void	rra(t_stack *stack_a)
{
	rtr(stack_a);
	print_string("rra");
}

void	rrb(t_stack *stack_b)
{
	rtr(stack_b);
	print_string("rrb");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rtr(stack_a);
	rtr(stack_b);
	print_string("rrr");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_a && stack_a->top)
	{
		temp = stack_a->top;
		stack_a->top = stack_a->top->next;
		temp->next = stack_b->top;
		stack_b->top = temp;
	}
	print_string("pb");
}
