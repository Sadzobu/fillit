#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	ft_gen_tetr(void)
{
    int		i;
    int		j;
    int		n_fig;
    int		n_v;
    int		strt_i;
    int		strt_j;
    char	**tetr;
    int		**len_i;
    int		**len_j;

    len_i = (int**)malloc(sizeof(int*) * 5);
    len_i[0] = (int*)malloc(sizeof(int) * 4);
    len_i[1] = (int*)malloc(sizeof(int) * 4);
    len_i[2] = (int*)malloc(sizeof(int) * 8);
    len_i[3] = (int*)malloc(sizeof(int) * 1);
    len_i[4] = (int*)malloc(sizeof(int) * 2);

    len_j = (int**)malloc(sizeof(int*) * 5);
    len_j[0] = (int*)malloc(sizeof(int) * 4);
    len_j[1] = (int*)malloc(sizeof(int) * 4);
    len_j[2] = (int*)malloc(sizeof(int) * 8);
    len_j[3] = (int*)malloc(sizeof(int) * 1);
    len_j[4] = (int*)malloc(sizeof(int) * 2);

    len_i[0][0] =  1; len_j[0][0] =  2;
    len_i[0][1] =  2; len_j[0][1] =  1;
    len_i[0][2] = -1; len_j[0][2] =  2;
    len_i[0][3] = -2; len_j[0][3] =  1;

    len_i[1][0] = -1; len_j[1][0] =  2;
    len_i[1][1] =  1; len_j[1][1] =  2;
    len_i[1][2] =  2; len_j[1][2] =  1;
    len_i[1][3] =  2; len_j[1][3] = -1;

    len_i[2][0] =  2; len_j[2][0] =  1;
    len_i[2][1] = -2; len_j[2][1] =  1;
    len_i[2][2] = -1; len_j[2][2] =  2;
    len_i[2][3] =  1; len_j[2][3] =  2;
    len_i[2][4] =  1; len_j[2][4] =  2;
    len_i[2][5] =  1; len_j[2][5] =  2;
    len_i[2][6] =  2; len_j[2][6] =  1;
    len_i[2][7] =  2; len_j[2][7] =  1;

    len_i[3][0] =  1; len_j[3][0] = 1;

    len_i[4][0] =  3; len_j[4][0] = 0;
    len_i[4][1] =  0; len_j[4][1] = 3;
    
    tetr = (char **)malloc(sizeof(char *) * 4);
    i = -1;
    while (++i < 4)
        tetr[i] = (char *)malloc(sizeof(char) * 4);
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 4)
            tetr[i][j] = '.';
    }
    n_fig = rand() % 5;
    switch (n_fig)
    {
    case 0:
        n_v = rand() % 4;
        break;
    case 1:
        n_v = rand() % 4;
        break;
    case 2:
        n_v = rand() % 8;
        break;
    case 3:
        n_v = 0;
        break;
    case 4:
        n_v = rand() % 2;
        break;
    }
    
    while ((((strt_i = rand() % 4) + len_i[n_fig][n_v]) > 3) || ((strt_i + len_i[n_fig][n_v]) < 0)
        || (((strt_j = rand() % 4) + len_j[n_fig][n_v]) > 3) || ((strt_j + len_j[n_fig][n_v]) < 0))
        ;
    switch (n_fig)
    {
    case 0:
        switch (n_v)
        {
        case 0:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j + 2] = '#';
            break;
        case 1:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i + 2][strt_j + 1] = '#';
            break;
        case 2:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i - 1][strt_j + 1] = '#';
            tetr[strt_i - 1][strt_j + 2] = '#';
            break;
        case 3:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i - 1][strt_j] = '#';
            tetr[strt_i - 1][strt_j + 1] = '#';
            tetr[strt_i - 2][strt_j + 1] = '#';
            break;
        }
        break;
    case 1:
        switch (n_v)
        {
        case 0:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i - 1][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            break;
        case 1:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            break;
        case 2:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i + 2][strt_j] = '#';
            break;
        case 3:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 1][strt_j - 1] = '#';
            tetr[strt_i + 2][strt_j] = '#';
            break;
        }
        break;
    case 2:
        switch(n_v)
        {
        case 0:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 2][strt_j] = '#';
            tetr[strt_i + 2][strt_j + 1] = '#';
            break;
        case 1:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i - 1][strt_j + 1] = '#';
            tetr[strt_i - 2][strt_j + 1] = '#';
            break;
        case 2:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            tetr[strt_i - 1][strt_j + 2] = '#';
            break;
        case 3:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            tetr[strt_i + 1][strt_j + 2] = '#';
            break;
        case 4:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            break;
        case 5:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j + 2] = '#';
            break;
        case 6:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 2][strt_j] = '#';
            break;
        case 7:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i + 1][strt_j + 1] = '#';
            tetr[strt_i + 2][strt_j + 1] = '#';
            break;
        }
        break;
    case 3:
        tetr[strt_i][strt_j] = '#';
        tetr[strt_i][strt_j + 1] = '#';
        tetr[strt_i + 1][strt_j] = '#';
        tetr[strt_i + 1][strt_j + 1] = '#';
        break;
    case 4:
        switch(n_v)
        {
        case 0:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i + 1][strt_j] = '#';
            tetr[strt_i + 2][strt_j] = '#';
            tetr[strt_i + 3][strt_j] = '#';
            break;
        case 1:
            tetr[strt_i][strt_j] = '#';
            tetr[strt_i][strt_j + 1] = '#';
            tetr[strt_i][strt_j + 2] = '#';
            tetr[strt_i][strt_j + 3] = '#';
            break;
        }
        break;
    }
/*    printf("Figure: %d\nVariant: %d\nStarting Coordinates:\n\tx: %d\n\ty: %d\n", n_fig, n_v, strt_i, strt_j);
    printf("Len row: %d\nLen column: %d\n", len_i[n_fig][n_v], len_j[n_fig][n_v]);
    printf("The generated figure looks like this\n");*/
    
    i = -1;
    while (++i < 4)
    {
        j = -1;
        while (++j < 3)
            printf("%c ", tetr[i][j]);
        printf("%c", tetr[i][j]);
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    int nbr;

    srand(time(NULL));
    
    if (argc == 2)
    {
        nbr = atoi(argv[1]);
        while (nbr-- > 1)
        {
            ft_gen_tetr();
            printf("\n");
        }
        ft_gen_tetr();
    }
    return (0);
}
