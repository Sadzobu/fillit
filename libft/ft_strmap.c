/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:45:05 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 19:46:03 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*res;
	unsigned int	i;

	if (s && f)
	{
		res = (char *)malloc(sizeof(*res) * (ft_strlen(s) + 1));
		if (res)
		{
			i = 0;
			while (s[i])
			{
				res[i] = f(s[i]);
				i++;
			}
			res[i] = '\0';
			return (res);
		}
	}
	return (NULL);
}
