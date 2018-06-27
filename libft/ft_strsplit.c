/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:59:59 by sshih             #+#    #+#             */
/*   Updated: 2018/05/13 14:33:30 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		if (s[j] != '\0' && s[j] != c)
		{
			new[i] = ft_malloc_word(s, c, j);
			i++;
			while (s[j] != c && s[j] != '\0')
				j++;
		}
	}
	new[i] = 0;
	return (new);
}
