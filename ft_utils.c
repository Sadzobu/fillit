/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:29:09 by ncammie           #+#    #+#             */
/*   Updated: 2019/06/18 20:29:10 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_list		*ft_listfree(t_list *list)
{
	t_tetr	*tetr;
	t_list	*next;

	while (list)
	{
		tetr = (t_tetr *)list->content;
		next = list->next;
		ft_tetrfree(tetr);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		ft_tetrfree(t_tetr *tetr)
{
	int y;

	y = -1;
	while (++y < tetr->height)
		ft_memdel((void **)(&(tetr->pos[y])));
	ft_memdel((void **)(&(tetr->pos)));
	ft_memdel((void **)&tetr);
}

t_tetr		*ft_tetrnew(char **pos, int width, int height, char symb)
{
	t_tetr		*tetr;

	tetr = ft_memalloc(sizeof(t_tetr));
	tetr->pos = pos;
	tetr->width = width;
	tetr->height = height;
	tetr->symb = symb;
	return (tetr);
}

int		ft_tetrcanplace(t_tetr *tetr, t_map *map, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < tetr->width)
	{
		j = -1;
		while (++j < tetr->height)
			if (tetr->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
    }
    return (1);
}

void	ft_tetrplace(t_tetr *tetr, t_map *map, int x, int y, char c)
{
    int i;
    int j;
    
    i = -1;
    while (++i < tetr->width)
    {
        j = -1;
        while (++j < tetr->height)
            if (tetr->pos[j][i] == '#')
                map->array[y + j][x + i] = c;
    }
}
