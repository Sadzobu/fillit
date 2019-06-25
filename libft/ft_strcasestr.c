#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t lenh;
	size_t lenn;
	size_t i;

	if (!*(char*)needle)
		return ((char*)haystack);
	lenh = ft_strlen(haystack);
	lenn = ft_strlen(needle);
	if (lenn > lenh)
		return (NULL);
	i = -1;
	while (++i <= lenh - lenn)
		if (!ft_strncasecmp(haystack + i, needle, lenn))
			return ((char*)haystack + i);
	return (NULL);
}
