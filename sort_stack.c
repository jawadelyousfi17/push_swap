/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:26:21 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 20:26:35 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_first(char **str, int size)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks_a_b(&stack_a, &stack_b, str, size);
	if (is_stack_sorted(&stack_a))
	{
		clean_stacks(&stack_a, &stack_b);
	}
	else if (stack_a.length == 2)
	{
		sa(&stack_a, 1);
		clean_stacks(&stack_a, &stack_b);
	}
	else if (stack_a.length == 3)
	{
		sort_stack_of_3(&stack_a);
		clean_stacks(&stack_a, &stack_b);
	}
	else
		check_and_sort(&stack_a, &stack_b);
}

void	check_and_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_index;

	if (stack_a->length > 4)
		pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	from_a_to_b(stack_a, stack_b);
	max_index = index_of(stack_b->arr, stack_b->length,
			ft_max(stack_b->arr, stack_b->length));
	if (stack_b->length > 1)
		bring_top_top_b(stack_b, max_index);
	sort_stack_of_3(stack_a);
	back_to_a(stack_a, stack_b, stack_b->length);
	while (!is_stack_sorted(stack_a))
		rra(stack_a, 1);
	clean_stacks(stack_a, stack_b);
}

void	clean_stacks(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
}

void	sort_stack_of_3(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->arr[2];
	b = stack->arr[1];
	c = stack->arr[0];
	if (a == ft_min(stack->arr, 3))
	{
		if (b > c)
		{
			rra(stack, 1);
			sa(stack, 1);
		}
	}
	else if (a == ft_max(stack->arr, 3))
	{
		ra(stack, 1);
		if (b > c)
			sa(stack, 1);
	}
	else if (b < c)
		sa(stack, 1);
	else
		rra(stack, 1);
}

int	is_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->length - 1)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
