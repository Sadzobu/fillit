#include "libft.h"

char	*ft_strlowcase(char *str)
{
    char *res;

    res = str;
    while (*str)
    {
        *str = ft_tolower((int)*str);
        str++;
    }
    return (res);
}
