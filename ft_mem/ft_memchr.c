/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:25:44 by rantario          #+#    #+#             */
/*   Updated: 2021/10/07 13:41:59 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	UC		*s;
	size_t	i;

	i = 0;
	s = (UC *)str;
	while (i < n)
	{
		if ((UC)s[i] == (UC)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
