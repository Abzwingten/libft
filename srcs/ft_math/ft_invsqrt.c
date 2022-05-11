/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invsqrt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:08:27 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 19:59:41 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_invsqrt(float number)
{
	long		i;
	float		half;
	float		y;
	const float	threehalves = 1.5F;

	half = number * 0.5F;
	y = number;
	i = *(long *) &y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *) &i;
	y = y * (threehalves - (half * y * y));
	return (y);
}
