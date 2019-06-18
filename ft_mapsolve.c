#include "fillit.h"
#include "libft.h"

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

int			ft_mapsolve(t_map *map, t_list *list)
{
    int		x;
    int		y;
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
                ft_tetrplace(tetr, map, x, y, tetr->symb);
                if (ft_mapsolve(map, list->next))
                    return (1);
                else
                    ft_tetrplace(tetr, map, x, y, '.');
            }
    }
    return (0);
}

int		ft_exit_error(char *msg)
{
    ft_putstr_fd(msg, 1);
    return (1);
}
