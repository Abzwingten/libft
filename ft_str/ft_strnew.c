#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = ft_memalloc(size);
	return (str);
}
