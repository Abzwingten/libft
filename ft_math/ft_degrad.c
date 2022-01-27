/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_degrad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 13:09:55 by rantario          #+#    #+#             */
/*   Updated: 2022/01/24 17:01:55 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PI 
# define M_PI 3.14159265358979323846264338327950288
#endif

float	to_degrees(float radians)
{
	return (radians * (180.0 / M_PI));
}

float	to_radians(float degrees)
{
	return (degrees * (M_PI / 180.0));
}
