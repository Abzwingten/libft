/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:26 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t num)
{
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL && num > 0)
		return (NULL);
	d = dst;
	s = src;
	while (num--)
		*d++ = *s++;
	return (dst);
}
