#include "fillit.h"
#include "libft.h"

t_list		*ft_tetrread(int fd)
{
    int		br;
    char	*buf;
    char	symb;
    t_list	*list;

    list = NULL;
    symb = 'A';
    buf  = (char *)malloc(sizeof(char) * 21);
    while ((br = read(fd, buf, 21)) >= 20)
    {
        if (!ft_tetrvalidate(buf, br))
        {
            ft_memdel(&buf);
            return (ft_listfree(list));
        }
        ft_lstadd(&list, ft_lstnew(ft_tetrseparate(buf, symb++), sizeof(t_tetr)));
    }
    ft_memdel(&buf);
    if (br)
        return (ft_listfree(list));
    ft_lstrev(list);
    return (list);
}

int	ft_tetrvalidate(char *buf, int br)
{
    int i;
    int	cnt;
    int cnc;
    
    while (i < 20)
    {
        if (((i % 5) == 4) && str[i] != '\n')
            return (1);
        if (((i % 5) < 4) && !(str[i] == '#' || str[i] == '.'))
            return (1);
        if ((str[i] == '#') && ++cnt > 4)
            return (1);
        if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				cnc++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				cnc++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				cnc++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				cnc++;
        }
    }
    if (br == 21 && buf[20] != '\n')
        return (1);
    return (cnc == 6 || cnc == 8);
}

t_tetr	*ft_tetrseparate(buf, symb)
{
    char **fig;

    
    
}

