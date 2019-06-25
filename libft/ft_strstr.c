/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:50:13 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 18:50:59 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t lenh;
	size_t lenn;
	size_t i;

	if (!*(char*)needle)
		return ((char*)haystack);
	lenh = ft_strlen(haystack);
	lenn = ft_strlen(needle);
	if (lenn > lenh)
		return (NULL);
	i = -1;
	while (++i <= lenh - lenn)
		if (!ft_strncmp(haystack + i, needle, lenn))
			return ((char*)haystack + i);
	return (NULL);
}
