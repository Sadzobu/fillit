/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:42:47 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 18:43:30 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	if (ft_strlen(src) < n)
		ft_strcpy(dest + ft_strlen(dest), src);
	else
	{
		dest[ft_strlen(dest) + n] = '\0';
		ft_strncpy(dest + ft_strlen(dest), src, n);
	}
	return (dest);
}
