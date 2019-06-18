#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>
# include "libft.h"

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_tetr
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_tetr;



void			ft_mapprint(t_map *map);
void			ft_mapfree(t_map *map);
t_map			*ft_mapnew(int size);
int				ft_mapsolve(t_map *map, t_list *list);

t_list			*ft_tetrread(int fd);
t_tetr			*ft_tetrnew(char **pos, int width, int height, char c);
void			ft_tetrfree(t_tetr *tetr);
void			ft_tetrplace(t_tetr *tetr, t_map *map, int x, int y, char c);
int				ft_tetrcanplace(t_tetr *tetr, t_map *map, int x, int y);
int				ft_tetrvalidate(char *buf, int br);
t_tetr			*ft_tetrseparate(char *pos, char value);

t_list			*ft_listfree(t_list *list);
int				ft_exit_error(char *msg);

#endif
