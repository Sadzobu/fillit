#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
    char	**tetr_ar;
    int		i;
    int		fd;
    int		rr;
    int		res_ar[5] = {0, 0, 0, 0, 0};

    i = -1;
    tetr_ar = (char **)malloc(sizeof(char *) * 4);
    while (++i < 4)
        tetr_ar[i] = (char *)malloc(sizeof(char) * 4);
    if (argc < 2)
    {
        printf("usage : ./fillit [filename]\n");
        return (0);
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        while ((rr = ft_read_tetr(fd, tetr_ar)) > 0)
            if ((rr = ft_verify_tetr(tetr_ar)) >= 0)
                res_ar[rr]++;
        if (rr < 0)
        {
            printf("error\n");
            return (0);
        }
        if ((rr = ft_verify_tetr(tetr_ar)) >= 0)
              res_ar[rr]++;
        if (rr < 0)
        {
            printf("error\n");
            return (0);
        }
        printf("%d %d %d %d %d\n", res_ar[0], res_ar[1], res_ar[2], res_ar[3], res_ar[4]);
    }
    return (0);
}
