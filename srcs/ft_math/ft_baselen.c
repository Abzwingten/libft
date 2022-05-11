/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:10:27 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 19:59:23 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_baselen(long num, int base)
{
	int		size;

	size = 0;
	if (base < 2)
		return (0);
	if (num == 0)
		return (1);
	if (num < 0)
		size++;
	while (num != 0)
	{
		num = num / base;
		size++;
	}
	return (size);
}
