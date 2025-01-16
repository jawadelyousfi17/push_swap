/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jel-yous <jel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:36:39 by jel-yous          #+#    #+#             */
/*   Updated: 2025/01/16 20:16:01 by jel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

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
