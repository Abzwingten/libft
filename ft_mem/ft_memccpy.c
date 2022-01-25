/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:56:57 by sherbert          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t num)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	dest = (unsigned char *)d;
	src = (unsigned char *)s;
	i = 0;
	while (i < num)
	{
		*dest = *src;
		if (*dest == (unsigned char)c)
		{
			dest++;
			return (dest);
		}
		i++;
		dest++;
		src++;
	}
	return (NULL);
}
