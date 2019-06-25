/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:09:43 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 20:05:54 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_cntwrd(char const *s, char c)
{
	size_t	res;
	size_t	len;
	size_t	i;

	res = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			res++;
		i++;
	}
	return (res);
}

static	size_t	ft_cntsmb(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (s[res] && s[res] != c)
		res++;
	return (res);
}

static	char	**ft_memdelall(char ***s)
{
	char **tmp;

	tmp = *s;
	while (*tmp)
		free(*tmp++);
	free(tmp);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	pos;
	char	**res;

	if (s)
		if ((res = (char **)malloc(sizeof(*res) * (ft_cntwrd(s, c) + 1))))
		{
			i = 0;
			j = 0;
			pos = 0;
			while (j < (ft_cntwrd(s, c)))
				if (s[i++] != c)
				{
					pos = i - 1;
					if (!(res[j++] = ft_strsub(s, pos, ft_cntsmb(s + pos, c))))
						return (ft_memdelall(&res));
					i += ft_cntsmb(s + pos, c);
				}
			res[j] = NULL;
			return (res);
		}
	return (NULL);
}
