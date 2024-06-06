/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzal2 <fgonzal2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 10:21:33 by fgonzal2          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:14 by fgonzal2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	stack_sort(t_stack *stack)
{
	if (stack_len(stack) < 2)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	node_top_a(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper)
			ra(stack);
		else
			rra(stack);
		stack_index_side(*stack);
	}
}

void	node_top_b(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper)
			rb(stack);
		else
			rrb(stack);
		stack_index_side(*stack);
	}
}

void stack_index_side(t_stack *stack)
{
	int	a;
	int	b;

	i = 0;
	b = (stack_len(stack) +1) /2;
	while (stack)
	{
		stack->index = ++a;
		stack->is_mid = b;
		if(a <= b)
		{
			stack->is_upper = 1;
			stack->is_down = b -1;
		}
		else
		{
			stack->is_upper = 0;
			stack->is_down = a - b;
		}
		stack = stack->next;
	}
}


t_stack	stack_structure(t_stack *a, t_stack *b)
{
	stack_index(a);
	stack_index(b);
	stack_target(a, b);
	return (stack_cost(a, b));
}