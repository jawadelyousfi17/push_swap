/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:30:28 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 22:48:04 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
