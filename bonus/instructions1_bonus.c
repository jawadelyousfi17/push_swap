/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:04:47 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 15:44:03 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pb(t_stack *a, t_stack *b, int flag)
{
	if (b->top >= b->size - 1 || a->top == -1)
		return ;
	push_to_stack(b, pop_from_stack(a));
	if (flag)
		ft_printf("pb\n");
}

void	pa(t_stack *a, t_stack *b, int flag)
{
	if (a->top >= a->size - 1 || b->top == -1)
		return ;
	push_to_stack(a, pop_from_stack(b));
	if (flag)
		ft_printf("pa\n");
}

void	sa(t_stack *a, int flag)
{
	int	tmp;

	if (a->top <= 0)
		return ;
	tmp = a->arr[a->top];
	a->arr[a->top] = a->arr[a->top - 1];
	a->arr[a->top - 1] = tmp;
	if (flag)
		ft_printf("sa\n");
}

void	rra(t_stack *a, int flag)
{
	int	i;
	int	tmp;

	if (a->top <= 0)
		return ;
	tmp = a->arr[0];
	i = 0;
	while (i < a->top)
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[a->top] = tmp;
	if (flag)
		ft_printf("rra\n");
}

void	ra(t_stack *a, int flag)
{
	int	i;
	int	tmp;

	if (a->top <= 0)
		return ;
	tmp = a->arr[a->top];
	i = a->top;
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = tmp;
	if (flag)
		ft_printf("ra\n");
}
