/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:54:58 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 20:53:00 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int					sign;
	unsigned long int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr && ft_isdigit(*nptr))
	{
		if ((result > 922337203685477500 || (result == 922337203685477500 &&
											(*nptr - '0') > 7)) && sign == 1)
			return (-1);
		if ((result > 922337203685477500 || (result == 922337203685477500 &&
											(*nptr - '0') > 8)) && sign == -1)
			return (0);
		result = (result * 10) + (*nptr++ - '0');
	}
	return ((int)(result * sign));
}
