/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:14:55 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 20:16:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_nbrlen(long num)
{
	int		size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		size++;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}
