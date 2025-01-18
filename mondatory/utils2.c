/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/18 15:22:25 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_max_2(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_strjoin_2(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*joined;

	len2 = ft_strlen(s2);
	len1 = ft_strlen(s1);
	i = 0;
	j = 0;
	joined = (char *)malloc(len1 + len2 + 1);
	if (!joined)
		return (free((void *) s1), NULL);
	while (i < len1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free((void *) s1);
	return (joined);
}
