/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:49:46 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/18 15:34:25 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_args(char **av, int ac)
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

void	exec_commands(char **str, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (str[i])
		do_inst(a, b, str[i++]);
	if (is_stack_sorted(a) && b->length == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(a->arr);
	free(b->arr);
	free_matrix(str);
}

char	**read_from_input()
{
	char	*inst;
	char	*instructions;
	char	**splited;

	instructions = NULL;
	inst = get_next_line_2(STDIN_FILENO, START);
	while (inst)
	{
		if (get_instruction(inst) == INVL_INST)
			return (free(inst), free(instructions), get_next_line_2(0, END),  NULL);
		instructions = ft_strjoin_2(instructions, inst);
		free(inst);
		if (!instructions)
			return (NULL);
		instructions = ft_strjoin_2(instructions, " ");
		if (!instructions)
			return (NULL);
		inst = get_next_line_2(STDIN_FILENO, START);
	}
	splited = ft_split(instructions, ' ');
	return (free(instructions), splited);
}

void	check_is_sorted(char **str, int size)
{
	t_stack	a;
	t_stack	b;
	char	**splited;

	init_stacks_a_b(&a, &b, str, size);
	splited = read_from_input();
	if (!splited)
		clean_stacks_and_exit(&a, &b);
	exec_commands(splited , &a, &b);
}

int	main(int ac, char **av)
{
	int		size;
	char	**str;

	if (ac < 2)
		return (EXIT_FAILURE);
	str = parse_args(ac, av);
	if (!check_args(av, ac) || !str)
		custom_exit("Error\n");
	size = check_valid_args(str);
	if (size == 0)
	{
		free_matrix(str);
		custom_exit("Error\n");
	}
	check_is_sorted(str, size);
	return (0);
}
