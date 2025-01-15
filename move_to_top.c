/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:28:42 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 19:28:58 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void bring_top_top_b(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRB;
    else
        instruction = RB;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RB)
            rb(stack, 1);
        if (instruction == RRB)
            rrb(stack, 1);
        i++;
    }
}

void bring_top_top_a(t_stack *stack, int target_index)
{
    int instruction;
    int moves_count;
    int i;

    moves_count = get_move_index(stack, target_index);
    if (target_index <= stack->length / 2)
        instruction = RRA;
    else
        instruction = RA;
    i = 0;
    while (i < moves_count)
    {
        if (instruction == RA)
            ra(stack, 1);
        if (instruction == RRA)
            rra(stack, 1);
        i++;
    }
}
