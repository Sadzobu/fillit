/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:37:10 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 18:37:56 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (n)
		if (*(unsigned char*)s1 == *(unsigned char*)s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*(unsigned char*)s1 - (*(unsigned char*)s2));
	return (0);
}
