#include "pushswap.h"

char	*ft_strneww(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = ft_strneww(len);
	if (!str)
		return (NULL);
	j = start;
	str[len] = '\0';
	while (len-- && s[j])
		str[i++] = s[j++];
	return (str);
}
