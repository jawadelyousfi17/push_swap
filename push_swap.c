/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:49:12 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 20:23:18 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i++]) == 0)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		size;
	char	**str;

	if (ac < 2)
		return (EXIT_FAILURE);
	str = parse_args(ac, av);
	if (!check_args(av, ac) || !str)
		custom_exit("ERROR\n");
	size = check_valid_args(str);
	if (!size)
	{
		free_matrix(str);
		custom_exit("ERROR\n");
	}
	sort_stack_first(str, size);
	return (0);
}
