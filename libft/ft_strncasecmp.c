#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
    unsigned char	*s3;
	unsigned char	*s4;
    int				result;

	s3 = (unsigned char *)s1;
	s4 = (unsigned char *)s2;
    if (n == 0)
        return (0);
    while (((result = ft_tolower((int)*s3) - ft_tolower((int)*s4++)) == 0) && n--)
        if (!*s3++ || !n)
            break;
    return (result);
}
