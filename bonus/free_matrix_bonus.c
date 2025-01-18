/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:29 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/18 15:38:44 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	**free_matrix(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return (NULL);
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	return (NULL);
}

void	invalid_inst(t_stack *a, t_stack *b, char *str)
{
	free(str);
	free(a->arr);
	free(b->arr);
	custom_exit("Error\n");
}

void	clean_stacks_and_exit(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	custom_exit("Error\n");
}
