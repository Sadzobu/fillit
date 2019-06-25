/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:41:18 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 18:41:45 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t size;

	size = ft_strlen(src);
	if (size > n)
		size = n;
	if (size != n)
		ft_memset(dest + size, '\0', n - size);
	return ((char*)ft_memcpy(dest, src, size));
}
