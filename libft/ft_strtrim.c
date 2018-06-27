/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 23:55:32 by sshih             #+#    #+#             */
/*   Updated: 2018/05/13 15:22:57 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	beg_space(char const *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	return (i);
}

static int	end_space(char const *str)
{
	int		i;

	i = ft_strlen(str);
	if (i == 0)
		return (0);
	while (i > 0 && (str[i - 1] == ' ' || str[i - 1] == '\t' ||
				str[i - 1] == '\n'))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		str_len;
	char	*str;

	if (!s)
		return (NULL);
	start = beg_space(s);
	str_len = end_space(s) - start;
	if (str_len <= 0)
		return (ft_strnew(0));
	str = ft_strsub(s, start, str_len);
	return (str);
}
