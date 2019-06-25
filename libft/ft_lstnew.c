/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:26:32 by ncammie           #+#    #+#             */
/*   Updated: 2019/04/10 20:54:14 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if ((res = (t_list *)malloc(sizeof(t_list))))
	{
		if (!content)
		{
			res->content = NULL;
			res->content_size = 0;
			res->next = NULL;
			return (res);
		}
		else
		{
			if ((res->content = (void *)malloc(content_size)))
			{
				ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
				res->next = NULL;
				return (res);
			}
			free(res);
		}
	}
	return (NULL);
}
