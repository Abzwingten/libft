/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:12:41 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 15:29:34 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_power(int num, UI power)
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

float	ft_powerf(float num, int power)
{
	float	temp;

	if (power == 0)
		return (1);
	temp = ft_powerf (num, power / 2);
	if ((power % 2) == 0)
		return (temp * temp);
	else
	{
		if (power > 0)
			return (num * temp * temp);
		else
			return ((temp * temp) / num);
	}
}
