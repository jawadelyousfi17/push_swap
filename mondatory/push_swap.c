/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:12 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/21 20:00:55 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_empty(char *s)
{
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (1);
}

static int	check_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i]) == 0 || ft_is_empty(av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		size;
	char	**str;

	if (ac < 2)
		return (EXIT_FAILURE);
	if (!check_args(av, ac))
		custom_exit("Error\n");
	str = parse_args(ac, av);
	if (!str)
		custom_exit("Error\n");
	size = check_valid_args(str);
	if (!size)
	{
		free_matrix(str);
		custom_exit("Error\n");
	}
	sort_stack_first(str, size);
	return (0);
}
