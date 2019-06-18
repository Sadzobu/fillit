/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapsolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:29:18 by ncammie           #+#    #+#             */
/*   Updated: 2019/06/18 22:08:49 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>

void	ft_mapfree(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void **)&(map->array[i]));
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	ft_mapprint(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_putendl(map->array[i]);
}

t_map	*ft_mapnew(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
	{
		map->array[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			map->array[i][j] = '.';
	}
	return (map);
}

int		ft_mapsolve(t_map *map, t_list *list)
{
	int		x;
	int		y;
	int		coord[2];
	t_tetr	*tetr;

	if (list == NULL)
		return (1);
	tetr = (t_tetr *)(list->content);
	y = -1;
	while (++y < map->size - tetr->height + 1)
	{
		x = -1;
		while (++x < map->size - tetr->width + 1)
			if (ft_tetrcanplace(tetr, map, x, y))
			{
				coord[0] = x;
				coord[1] = y;
				ft_tetrplace(tetr, map, coord, tetr->symb);
				if (ft_mapsolve(map, list->next))
					return (1);
				else
					ft_tetrplace(tetr, map, coord, '.');
			}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		size;
	t_list	*list;
	t_map	*map;

	size = 2;
	if (argc != 2)
		return (ft_exit_error("usage: fillit input_file\n"));
	if ((list = ft_tetrread(open(argv[1], O_RDONLY))) == NULL)
		return (ft_exit_error("error\n"));
	while (!ft_mapsolve((map = ft_mapnew(size++)), list))
		ft_mapfree(map);
	ft_mapprint(map);
	ft_mapfree(map);
	ft_listfree(list);
	return (0);
}
