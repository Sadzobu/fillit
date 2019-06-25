/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:19:06 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 21:49:36 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char*)dest;
	while (n--)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*tmp++ = *(unsigned char*)src;
			return (tmp);
		}
		else
			*tmp++ = *(unsigned char*)src++;
	}
	return (NULL);
}
