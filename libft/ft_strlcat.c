/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 21:32:33 by sshih             #+#    #+#             */
/*   Updated: 2018/05/13 11:08:46 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (n <= s1len)
		return (s2len + n);
	while ((s1[i] != '\0') && i < (n - 1))
		i++;
	while (*s2 && i < (n - 1))
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1len + s2len);
}
