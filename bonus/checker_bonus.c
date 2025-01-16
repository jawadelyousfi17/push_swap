/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:49:46 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 16:48:51 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int check_args(char **av, int ac)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (ft_strlen(av[i++]) == 0)
			return (0);
	}
	return (1);
}

void invalid_inst(t_stack *a, t_stack *b, char *str)
{
	free(str);
	free(a->arr);
	free(b->arr);
	custom_exit("ERROR\n");
}


void check_is_sorted(char **str, int size)
{
	t_stack stack_a;
	t_stack stack_b;
	char *inst;

	init_stacks_a_b(&stack_a, &stack_b, str, size);
	inst = get_next_line(STDIN_FILENO);
	while (inst)
	{
		do_inst(&stack_a, &stack_b, inst);
		free(inst);
		inst = get_next_line(STDIN_FILENO);
	}
	if (is_stack_sorted(&stack_a) && stack_b.length == 0)
	{
		ft_printf("OK\n");
	} else 
		ft_printf("KO\n");
	free(stack_a.arr);
	free(stack_b.arr);
}

void f()
{
	system("leaks checker");
}

int main(int ac, char **av)
{
	int size;
	char **str;

	if (ac < 2)
		return EXIT_FAILURE;
	str = parse_args(ac, av);
	if (!check_args(av, ac) || !str)
		custom_exit("ERROR\n");
	size = check_valid_args(str);
	if (size == 0)
	{
		free_matrix(str);
		custom_exit("ERROR\n");
	}
	check_is_sorted(str, size);
	atexit(f);
	return 0;
}