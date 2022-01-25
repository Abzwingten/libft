/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:09:55 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 15:09:02 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#ifndef M_PI 
# define M_PI 3.14159265358979323846264338327950288
#endif

float	ft_2degrees(float radians)
{
	return (radians * (180.0 / M_PI));
}

float	ft_2radians(float degrees)
{
	return (degrees * (M_PI / 180.0));
}
