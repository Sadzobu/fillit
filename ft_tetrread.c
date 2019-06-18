/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:11:19 by ncammie           #+#    #+#             */
/*   Updated: 2019/06/18 21:52:00 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_list	*ft_tetrread(int fd)
{
	int		br;
	char	*buf;
	char	symb[2];
	t_list	*list;
	t_tetr	*tetr;

	list = NULL;
	symb[0] = 'A';
	buf = ft_strnew(21);
	while ((br = read(fd, buf, 21)) >= 20)
	{
		if (!ft_tetrvalidate(buf, br))
			return (ft_free_return(&list, &buf));
		ft_lstadd(&list, ft_lstnew((tetr = ft_tetrseparate(buf, symb[0]++)),
								sizeof(t_tetr)));
		ft_memdel((void **)&tetr);
		symb[1] = (br == 21);
	}
	ft_memdel((void **)&buf);
	if (br || symb[1])
		return (ft_listfree(list));
	ft_lstrev(&list);
	return (list);
}

int		ft_tetrvalidate(char *buf, int br)
{
	int i;
	int	cnt;
	int cnc;

	i = -1;
	cnt = 0;
	cnc = 0;
	while (++i < 20)
	{
		if (((i % 5 == 4) && buf[i] != '\n') ||
			((i % 5 < 4) && !(buf[i] == '#' || buf[i] == '.')))
			return (0);
		if (buf[i] == '#')
		{
			((i + 1) < 20 && buf[i + 1] == '#') ? cnc++ : 1;
			((i - 1) >= 0 && buf[i - 1] == '#') ? cnc++ : 1;
			((i + 5) < 20 && buf[i + 5] == '#') ? cnc++ : 1;
			((i - 5) >= 0 && buf[i - 5] == '#') ? cnc++ : 1;
		}
	}
	if (br == 21 && buf[20] != '\n')
		return (0);
	return (cnc == 6 || cnc == 8);
}

t_tetr	*ft_tetrseparate(char *buf, char symb)
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
			i / 5 < y[0] ? y[0] = i / 5 : 1;
			i / 5 > y[1] ? y[1] = i / 5 : 1;
			i % 5 < x[0] ? x[0] = i % 5 : 1;
			i % 5 > x[1] ? x[1] = i % 5 : 1;
		}
	pos = ft_memalloc(sizeof(char *) * (y[1] - y[0] + 1));
	i = -1;
	while (++i < y[1] - y[0] + 1)
		ft_strncpy((pos[i] = ft_strnew(x[1] - x[0] + 1)),
				buf + x[0] + (i + y[0]) * 5, x[1] - x[0] + 1);
	return ((tetr = ft_tetrnew(pos, x[1] - x[0] + 1, y[1] - y[0] + 1, symb)));
}

t_list	*ft_free_return(t_list **list, char **buf)
{
	ft_memdel((void **)buf);
	return (ft_listfree(*list));
}

int		ft_exit_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (1);
}
