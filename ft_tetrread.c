#include "fillit.h"
#include "libft.h"

t_list		*ft_tetrread(int fd)
{
    int		br;
    char	*buf;
    char	symb;
    t_list	*list;
    t_tetr  *tetr;

    list = NULL;
    symb = 'A';
    buf  = ft_strnew(21);
    while ((br = read(fd, buf, 21)) >= 20)
    {
        if (!ft_tetrvalidate(buf, br))
        {
            ft_memdel((void **)&buf);
            return (ft_listfree(list));
        }
        ft_lstadd(&list, ft_lstnew((tetr = ft_tetrseparate(buf, symb++)), sizeof(t_tetr))) ;
        ft_memdel((void **)&tetr);
    }
    ft_memdel((void **)&buf);
    if (br)
        return (ft_listfree(list));
    ft_lstrev(&list);
    return (list);
}

int	ft_tetrvalidate(char *buf, int br)
{
    int i;
    int	cnt;
    int cnc;

    i = -1;
    cnt = 0;
    cnc = 0;
    while (++i < 20)
    {
        if (((i % 5) == 4) && buf[i] != '\n')
            return (1);
        if (((i % 5) < 4) && !(buf[i] == '#' || buf[i] == '.'))
            return (1);
        if ((buf[i] == '#') && ++cnt > 4)
            return (1);
        if (buf[i] == '#')
		{
			if ((i + 1) < 20 && buf[i + 1] == '#')
				cnc++;
			if ((i - 1) >= 0 && buf[i - 1] == '#')
				cnc++;
			if ((i + 5) < 20 && buf[i + 5] == '#')
				cnc++;
			if ((i - 5) >= 0 && buf[i - 5] == '#')
				cnc++;
        }
    }
    if (br == 21 && buf[20] != '\n')
        return (1);
    return (cnc == 6 || cnc == 8);
}

t_tetr	*ft_tetrseparate(char *buf, char value)
{
	char		**pos;
	int			i;
    int			x[2];
    int			y[2];
	t_tetr		*tetr;

	i = -1;
    x[0] = 3;
    x[1] = 0;
    y[0] = 3;
    y[1] = 0;
	while (++i < 20)
		if (buf[i] == '#')
		{
			if (i / 5 < y[0])
				y[0] = i / 5;
			if (i / 5 > y[1])
				y[1] = i / 5;
			if (i % 5 < x[0])
				x[0] = i % 5;
			if (i % 5 > x[1])
				x[1] = i % 5;
		}
	pos = ft_memalloc(sizeof(char *) * (y[1] - y[0] + 1));
	i = -1;
	while (++i < y[1] - y[0] + 1)
	{
		pos[i] = ft_strnew(x[1] - x[0] + 1);
		ft_strncpy(pos[i], buf + x[0] + (i + y[0]) * 5, x[1] - x[0] + 1);
	}
	tetr = ft_tetrnew(pos, x[1] - x[0] + 1, y[1] - y[0] + 1, value);
	return (tetr);
}