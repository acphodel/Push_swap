/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <maavalya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:47:48 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/13 21:47:48 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	t_node	*temp;

	if (stack && stack->top && stack->top->next)
	{
		temp = stack->top;
		stack->top = temp->next;
		temp->next = stack->top->next;
		stack->top->next = temp;
	}
}

void	sa(t_stack *stack_a)
{
	s(stack_a);
	print_string("sa");
}

void	sb(t_stack *stack_b)
{
	s(stack_b);
	print_string("sb");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	s(stack_a);
	s(stack_b);
	print_string("ss");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b && stack_b->top)
	{
		temp = stack_b->top;
		stack_b->top = stack_b->top->next;
		temp->next = stack_a->top;
		stack_a->top = temp;
	}
	print_string("pa");
}
