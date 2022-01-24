/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:33 by rantario          #+#    #+#             */
/*   Updated: 2021/10/05 16:05:35 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
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
		while (n--)
			s1[n] = s2[n];
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (dest);
}
