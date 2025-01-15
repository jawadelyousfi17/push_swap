/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:49:40 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/15 19:49:55 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(t_stack *a, int flag)
{
    int i;
    int tmp;

    if (a->top <= 0)
        return;
    tmp = a->arr[a->top];
    for (i = a->top; i > 0; i--)
        a->arr[i] = a->arr[i - 1];
    a->arr[0] = tmp;
    if (flag)
        ft_printf("rb\n");
}

void sb(t_stack *a, int flag)
{
    int tmp;

    if (a->top <= 0)
        return ;
    tmp = a->arr[a->top];
    a->arr[a->top] = a->arr[a->top - 1];
    a->arr[a->top - 1] = tmp;
    if (flag)
        ft_printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    sa(a, 0);
    sb(b, 0);
    ft_printf("ss\n");
}

void rr(t_stack *a, t_stack *b)
{
    ra(a, 0);
    rb(b, 0);
    ft_printf("rr\n");
}



