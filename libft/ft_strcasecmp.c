#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
    unsigned char	*s3;
	unsigned char	*s4;
    int				result;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
    if (s3 == s4)
        return (0);
    while (((result = ft_tolower((int)*s3) - ft_tolower((int)*s4++)) == 0))
        if (!*s3++)
            break;
    return (result);
}
