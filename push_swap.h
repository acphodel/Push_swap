/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maavalya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:24:11 by maavalya          #+#    #+#             */
/*   Updated: 2024/04/26 11:24:13 by maavalya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "ft/ft.h"
# include "stdbool.h"
# include <unistd.h>

typedef struct s_number
{
	int	value;
	int	place;
}	t_number;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

void		print_message(char *message);
long long	long_atoi(const char *str);
void		swapper(int *nums, int size, int *sorted_nums);
void		bubble_sort(int *nums, int array_size);
void		sorter(struct s_stack *stack_a, struct s_stack *stack_b, int size);
bool		sorted(struct s_stack *stack);
void		three_sort(t_stack *stack);
void		two_sort(struct s_stack *stack_a);
void		butterfly(struct s_stack *stack_a, struct s_stack *stack_b,
				int size, int n);
int			get_position(t_stack *stack, int value);

void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

void		print_string(char *p);

char		*shorting_one(char	*input, char	*temp);
int			shorting_two(char *argv_i);

int			nums_and_check(char	*input);
int			*num_array(char *input);
void		send_back_to_a(struct s_stack *stack_a, struct s_stack *stack_b,
				int size, int n);
#endif
