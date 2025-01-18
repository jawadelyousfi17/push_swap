/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/18 15:39:11 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t');
}

long	ft_atol(const char *nptr)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*nptr && ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (*nptr && ft_isdigit(*nptr))
		result = result * 10 + *(nptr++) - 48;
	return (result * sign);
}

int	compare_str(char *str, char *str1)
{
	return (ft_strlen(str1) == ft_strlen(str)
		&& ft_strncmp(str, str1, ft_strlen(str1)) == 0);
}

int	get_instruction(char *inst)
{
	if (compare_str(inst, "sa"))
		return (SA);
	if (compare_str(inst, "sb"))
		return (SB);
	if (compare_str(inst, "ra"))
		return (RA);
	if (compare_str(inst, "rb"))
		return (RB);
	if (compare_str(inst, "rra"))
		return (RRA);
	if (compare_str(inst, "rrb"))
		return (RRB);
	if (compare_str(inst, "rr"))
		return (RR);
	if (compare_str(inst, "rrr"))
		return (RRR);
	if (compare_str(inst, "pa"))
		return (PA);
	if (compare_str(inst, "pb"))
		return (PB);
	if (compare_str(inst, "ss"))
		return (SS);
	return (INVL_INST);
}

void	do_inst(t_stack *a, t_stack *b, char *inst)
{
	if (get_instruction(inst) == SA)
		sa(a, 0);
	else if (get_instruction(inst) == SB)
		sb(b, 0);
	else if (get_instruction(inst) == SS)
		ss(a, b);
	else if (get_instruction(inst) == PA)
		pa(a, b, 0);
	else if (get_instruction(inst) == PB)
		pb(a, b, 0);
	else if (get_instruction(inst) == RA)
		ra(a, 0);
	else if (get_instruction(inst) == RB)
		rb(b, 0);
	else if (get_instruction(inst) == RRA)
		rra(a, 0);
	else if (get_instruction(inst) == RRB)
		rrb(b, 0);
	else if (get_instruction(inst) == RR)
		rr(a, b);
	else if (get_instruction(inst) == RRR)
		rrr(a, b);
	else
		invalid_inst(a, b, inst);
}
