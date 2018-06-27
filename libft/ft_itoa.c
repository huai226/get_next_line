/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:30:45 by sshih             #+#    #+#             */
/*   Updated: 2018/05/10 21:43:00 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countnb(int n)
{
	int count;

	count = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		count++;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		count;
	char	*new;
	int		neg;

	neg = 1;
	count = ft_countnb(n);
	if (n < 0)
	{
		count++;
		neg *= -1;
	}
	if ((new = (char*)malloc(sizeof(char) * (count + 1))) == 0)
		return (NULL);
	new[count] = '\0';
	count--;
	while (count > 0)
	{
		new[count--] = ((n % 10) * neg) + '0';
		n /= 10;
	}
	if (neg == -1)
		new[count] = '-';
	else
		new[count] = n % 10 + '0';
	return (new);
}
