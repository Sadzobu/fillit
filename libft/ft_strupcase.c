#include "libft.h"

char	*ft_strupcase(char *str)
{
    char *res;

    res = str;
    while (*str)
    {
        *str = ft_toupper((int)*str);
        str++;
    }
    return (res);
}
