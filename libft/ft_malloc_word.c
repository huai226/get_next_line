/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:17:11 by sshih             #+#    #+#             */
/*   Updated: 2018/05/13 14:51:53 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_malloc_word(char const *str, char c, int j)
{
	char	*word;
	int		i;
	int		count;
	int		tmp;

	count = 0;
	tmp = j;
	while (str[tmp] != c && str[tmp] != '\0')
	{
		tmp++;
		count++;
	}
	if (!(word = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	while (str[j] != c && str[j] != '\0')
	{
		word[i] = str[j];
		i++;
		j++;
	}
	word[i] = '\0';
	return (word);
}
