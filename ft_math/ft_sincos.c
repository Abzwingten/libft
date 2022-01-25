/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sincos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:03:32 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 17:44:58 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

float	ft_sin(float x, int limit)
{
	float	result;
	int		i;
	int		j;

	result = 0;
	x = ft_2radians(x);
	i = 1;
	j = 1;
	while (i <= limit)
	{
		if (i % 2 != 0)
			result += ft_powerf(x, j) / ft_factorial(j);
		else
			result -= ft_powerf(x, j) / ft_factorial(j);
		i++;
		j += 2;
	}
	return (result);
}

float	ft_sin(float x)
{
	float		y;
	const float	b = 4 / M_PI;
	const float	c = -4 / (M_S_PI);
	const float	p = 0.225;

	y = b * x + c * x * ft_abs(x);
	y = p * (y * ft_abs(y) - y) + y;
	return (y);
}

float	ft_cos(float x, int limit)
{
	float	result;
	int		i;
	int		j;

	result = 0;
	x = ft_2radians(x);
	i = 0;
	j = 0;
	while (i <= limit)
	{
		if (i % 2 != 0)
			result -= ft_powerf(x, j) / ft_factorial(j);
		else
			result += ft_powerf(x, j) / ft_factorial(j);
		i++;
		j += 2;
	}
	return (result);
}
