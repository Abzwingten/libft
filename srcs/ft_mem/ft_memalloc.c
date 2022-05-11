#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size + 1);
	if (result != NULL)
	{
		ft_memset(result, '\0', size);
	}
	return (result);
}
