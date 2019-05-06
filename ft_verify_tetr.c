#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int		ft_read_tetr(int fd, char **ar)
{
    int		res;
    int		i;
    char	**line;
    
    line = (char **)malloc(sizeof(char *));
    *line = NULL;
    i = -1;
    while (((res = get_next_line(fd, line)) > 0) && ((*(*line)) != '\0') && (i < 4) && (ft_strlen(*line) == 4))
            ar[++i] = *line;
    if (res < 0 || i != 3)
        return (-1);
    if (res == 0)
        return (0);
    if ((*(*line)) == '\0')
        return (1);
    else
        return (-1);
}

int		ft_verify_tetr(char **tetr)
{
    int		res;
    int		cnt;
    int		i;
    int		j;
    char	crd[4][2];

    cnt = 0;
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            if (tetr[i][j] == '#')
            {
                if (cnt > 3)
                    return (-1);
                crd[cnt][0] = i;
                crd[cnt][1] = j;
                cnt++;
            }
    }
    if (cnt != 4)
        return (-1);
    cnt = 0;
    res = 0;
    i = -1;
    while (++i < 4)
    {
        j = i;
        while (++j < 4)
        {
            if (crd[i][0] == crd[j][0])
                cnt++;
            if (crd[i][1] == crd[j][1])
                res++;
        }
    }
    if (cnt == 2 && res == 2)
        return (0);
    if (cnt == 2 || res == 2)
        return (1);
    if (cnt == 3 || res == 3)
    {
        if ((crd[0][1] == crd[2][1] && crd[1][0] == crd[3][0]) ||
            (crd[1][0] == crd[2][0] && crd[0][1] == crd[3][1]) ||
            (crd[1][1] == crd[3][1] && crd[0][0] == crd[2][0]))
            return (2);
        else
            return (3);
    }
    else
        return (4);
}
