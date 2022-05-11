/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:09:55 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 19:59:30 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	to_degrees(float radians)
{
	return (radians * (180.0 / M_PI));
}

float	to_radians(float degrees)
{
	return (degrees * (M_PI / 180.0));
}
