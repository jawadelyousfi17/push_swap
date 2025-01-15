/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:21:03 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 19:21:24 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void from_a_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int inst_a[2];
    int inst_b[2];
    int i;

    i = 0;
    while (stack_a->length > 3)
    {
        int cheapest_index = get_cheapest_index(stack_a, stack_b);
        int target_index = get_terget_index(stack_b, stack_a->arr[cheapest_index]);
        how_to_top_a_methode_2(stack_a, inst_a, cheapest_index);
        how_to_top_a_methode_2(stack_b, inst_b, target_index);
        handle_shared(stack_a, stack_b, inst_a, inst_b);
        pb(stack_a, stack_b, 1);
    }
}

void back_to_a(t_stack *stack_a, t_stack *stack_b, int size)
{
    int k;
    int a;

    a = 0;
    k = 0;
    while (size)
    {
        if (stack_b->arr[stack_b->top] > ft_max(stack_a->arr, stack_a->length) || stack_a->arr[stack_a->top] == stack_b->arr[stack_b->top] + 1)
            pa(stack_a, stack_b, 1);
        else
        {
            a = index_of(stack_a->arr, stack_a->size,
                         stack_b->arr[stack_b->top] + 1);
            k = 0;
            while (k < a + 1)
            {
                rra(stack_a, 1);
                k++;
            }
            pa(stack_a, stack_b, 1);
        }
        size--;
    }
}