/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:06:26 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 20:08:04 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int res;

	res = 0;
	if (n <= 0)
		res++;
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbrlen(n);
	res = ft_strnew(len);
	if (res)
	{
		sign = ((n < 0) ? 1 : 0);
		if (n < 0)
		{
			res[0] = '-';
			n *= -1;
		}
		while (len - sign)
		{
			res[--len] = n % 10 + '0';
			n /= 10;
		}
		return (res);
	}
	return (NULL);
}
