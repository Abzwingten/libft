/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:39 by rantario          #+#    #+#             */
/*   Updated: 2021/10/18 13:47:42 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	UC	*pointer;

	pointer = (UC *)str;
	while (len)
	{
		*(pointer + len - 1) = (UC)c;
		len--;
	}
	return (str);
}
