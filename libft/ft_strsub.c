/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:48:51 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 19:50:00 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	res = (char *)malloc(sizeof(*res) * (len + 1));
	if (s && res)
	{
		i = 0;
		while (len--)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
