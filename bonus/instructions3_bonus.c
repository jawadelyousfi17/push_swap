/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:50:05 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 16:20:40 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
}

void	rrb(t_stack *a, int flag)
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
		ft_printf("rrb\n");
}
