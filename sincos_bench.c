/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sincos_bench.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:30:02 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 17:42:30 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <math.h>

int main(void)
{
	float	i;
	int lim;
	
	float ftsin;
	float ftcos;
	float mtsin;
	float mtcos;
	float deltasin;
	float deltacos;
	
	i = 0;
	lim = 7;
	
	while (i <= 180)
	{
		ftsin = ft_sin(i);
		ftcos = ft_cos(i, lim);
		mtsin = sin(i);
		mtcos = cos(i);
		deltasin = (ftsin - mtsin) * 100;
		deltacos = (ftcos - mtcos) * 100;
		
		printf("ft_sin(%f) = %f\t\t", i, ftsin);
		printf("sin.h (%f) = %f\t\t", i, mtsin);
		printf("%f%%\n", deltasin);
		printf("ft_cos(%f) = %f\t\t", i, ftcos);
		printf("cos.h (%f) = %f\t\t", i, mtcos);
		printf("%f%%\n<----------------->\n", deltacos);

		i++;
	}
	return (0);
}