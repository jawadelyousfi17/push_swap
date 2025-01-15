/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:29:13 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 20:24:29 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_instruction_based_on_dir(t_stack *a, t_stack *b,
		int *inst, int stack)
{
	int	dir;

	dir = inst[1];
	if (stack == STACK_A)
	{
		if (dir == UP)
			ra(a, 1);
		if (dir == DOWN)
			rra(a, 1);
	}
	else
	{
		if (dir == UP)
			rb(b, 1);
		if (dir == DOWN)
			rrb(b, 1);
	}
	inst[0]--;
}

void	do_shared_instruction_based_on_dir(t_stack *a,
		t_stack *b, int *inst, int *instb)
{
	if (inst[1] == UP)
		rr(a, b);
	if (inst[1] == DOWN)
		rrr(a, b);
	inst[0]--;
	instb[0]--;
}

int	handle_shared(t_stack *stack_a, t_stack *stack_b, int *insta, int *instb)
{
	if (insta[1] == instb[1])
	{
		while (insta[0] && instb[0])
			do_shared_instruction_based_on_dir(stack_a, stack_b, insta, instb);
		while (insta[0])
			do_instruction_based_on_dir(stack_a, stack_b, insta, STACK_A);
		while (instb[0])
			do_instruction_based_on_dir(stack_a, stack_b, instb, STACK_B);
	}
	else
	{
		while (insta[0])
			do_instruction_based_on_dir(stack_a, stack_b, insta, STACK_A);
		while (instb[0])
			do_instruction_based_on_dir(stack_a, stack_b, instb, STACK_B);
	}
	return (0);
}

void	how_to_top_a_methode_2(t_stack *a, int *inst, int index)
{
	int	instruction;
	int	moves_count;

	moves_count = get_move_index(a, index);
	if (index <= a->length / 2)
		instruction = DOWN;
	else
		instruction = UP;
	inst[0] = moves_count;
	inst[1] = instruction;
}
