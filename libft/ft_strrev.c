/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:03:27 by sshih             #+#    #+#             */
/*   Updated: 2018/05/13 15:09:15 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	temp;
	int		len;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	len = i - 1;
	i = 0;
	while (i < len)
	{
		temp = str[len];
		str[len] = str[i];
		str[i] = temp;
		i++;
		len--;
	}
	return (str);
}
