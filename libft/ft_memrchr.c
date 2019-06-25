/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:17:35 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 20:17:52 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*((unsigned char*)s + n) == (unsigned char)c)
			return (void*)((unsigned char*)s + n);
	}
	return (NULL);
}
