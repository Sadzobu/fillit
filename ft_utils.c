#include "libft.h"
#include "fillit.h"

t_list		*ft_listfree(t_list *list)
{
	t_tetr	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_tetr *)list->content;
		next = list->next;
		ft_tetrfree(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		ft_tetrfree(t_tetr *tetr)
{
	int y;

	y = 0;
	while (y < tetr->height)
	{
		ft_memdel((void **)(&(tetr->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(tetr->pos)));
	ft_memdel((void **)&tetr);
}

t_tetr		*ft_tetrnew(char **pos, int width, int height, char value)
{
	t_tetr		*tetr;

	tetr = ft_memalloc(sizeof(t_tetr));
	tetr->pos = pos;
	tetr->width = width;
	tetr->height = height;
	tetr->value = value;
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
