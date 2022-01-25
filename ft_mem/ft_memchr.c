/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:44 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t num)
{
	UC		*s;
	size_t	i;

	i = 0;
	s = (UC *)str;
	while (i < num)
	{
		if ((UC)s[i] == (UC)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
