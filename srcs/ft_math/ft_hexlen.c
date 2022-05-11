/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:59:17 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 19:59:36 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(long num)
{
	int		size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		size++;
	while (num != 0)
	{
		num = num / 16;
		size++;
	}
	return (size);
}
