/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:12:41 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 19:59:51 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int num, unsigned int power)
{
	int	res;

	res = 1;
	while (num)
	{
		if (num & 1)
			res *= power;
		power *= power;
		num >>= 1;
	}
	return (res);
}
