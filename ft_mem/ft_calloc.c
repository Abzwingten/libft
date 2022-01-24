/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:24:44 by rantario          #+#    #+#             */
/*   Updated: 2021/10/18 13:48:58 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (size == 0 || num == 0)
		return (malloc(0));
	ptr = (void *)malloc(num * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, num * size);
	return (ptr);
}
