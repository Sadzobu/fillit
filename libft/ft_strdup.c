/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:39:29 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 18:40:31 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dest;
	char *tmp;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	tmp = dest;
	if (tmp)
	{
		while (*s)
			*tmp++ = *s++;
		*tmp = '\0';
		return (dest);
	}
	return (NULL);
}
