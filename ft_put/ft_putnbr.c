/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:26:14 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 14:54:05 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	write_nbr(long long int num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		write_nbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putnbr(int n)
{
	LLI	num;

	num = n;
	write_nbr(num);
}
