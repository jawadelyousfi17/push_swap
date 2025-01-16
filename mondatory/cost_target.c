/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:05 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 20:07:33 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_move_direction(t_stack *stack, int index)
{
	if (index <= stack->length / 2)
		return (UP);
	return (DOWN);
}

int	calcul_cost(t_stack *a, t_stack *b, int a_index)
{
	int	a_cost;
	int	b_cost;
	int	a_move_direction;
	int	b_move_direction;

	a_move_direction = get_move_direction(a, a_index);
	b_move_direction = get_move_direction(b,
			get_terget_index(b, a->arr[a_index]));
	a_cost = get_move_index(a, a_index);
	b_cost = get_move_index(b, get_terget_index(b, a->arr[a_index]));
	if (a_move_direction == b_move_direction)
		return (ft_max_2(a_cost, b_cost));
	return (a_cost + b_cost);
}

int	get_cheapest_index(t_stack *a, t_stack *b)
{
	int	cheapest_move_index;
	int	cost;
	int	temp_cost;
	int	i;

	i = 1;
	cheapest_move_index = 0;
	cost = calcul_cost(a, b, 0);
	while (i < a->length)
	{
		temp_cost = calcul_cost(a, b, i);
		if (temp_cost < cost)
		{
			cost = temp_cost;
			cheapest_move_index = i;
		}
		i++;
	}
	return (cheapest_move_index);
}

int	get_terget_index(t_stack *b, int item)
{
	int	max;
	int	i;
	int	closet_number;

	i = 0;
	closet_number = -1;
	max = ft_max(b->arr, b->length);
	if (item < ft_min(b->arr, b->length) || item > max)
		return (index_of(b->arr, b->length, max));
	while (i < b->length && closet_number == -1)
	{
		if (b->arr[i] < item)
			closet_number = b->arr[i];
		i++;
	}
	while (i < b->length)
	{
		if (b->arr[i] < item
			&& ft_abs(b->arr[i] - item) < ft_abs(closet_number - item))
			closet_number = b->arr[i];
		i++;
	}
	return (index_of(b->arr, b->length, closet_number));
}

int	get_move_index(t_stack *stack, int index)
{
	if (index <= stack->length / 2)
		return (index + 1);
	return (stack->length - index - 1);
}
