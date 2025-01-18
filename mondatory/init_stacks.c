/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:28 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 22:47:25 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_and_sort(t_stack *a, t_stack *b)
{
	int	*duplicate;
	int	i;
	int	size;

	size = a->size;
	duplicate = clone_array(a->arr, a->size);
	if (!duplicate)
	{
		free(a->arr);
		free(b->arr);
		custom_exit("Error\n");
	}
	sort_array(duplicate, a->size);
	i = 0;
	while (i < size)
	{
		a->arr[i] = index_of(duplicate, size, a->arr[i]);
		i++;
	}
	free(duplicate);
}

void	init_stacks_a_b(t_stack *a, t_stack *b, char **str, int size)
{
	init_stack(a, size);
	if (!a->arr)
	{
		free_matrix(str);
		custom_exit("Error\n");
	}
	initialize_stack_a(a, size, str);
	if (!check_duplicate(a))
	{
		free(a->arr);
		free_matrix(str);
		custom_exit("Error\n");
	}
	init_stack(b, size);
	if (!b->arr)
	{
		free_matrix(str);
		free(a->arr);
		custom_exit("Error\n");
	}
	free_matrix(str);
	duplicate_and_sort(a, b);
}
