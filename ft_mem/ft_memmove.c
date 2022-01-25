/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:33 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	UC		*s1;
	UC		*s2;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	s1 = (UC *)dest;
	s2 = (UC *)src;
	if (dest > src)
	{
		while (num--)
			s1[num] = s2[num];
	}
	else
	{
		while (i < num)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}
