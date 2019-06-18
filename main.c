/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncammie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:29:25 by ncammie           #+#    #+#             */
/*   Updated: 2019/06/18 21:42:34 by ncammie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>

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
