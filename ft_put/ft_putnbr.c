/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:26:14 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 18:54:02 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	write_nbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		write_nbr(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_putnbr(int n)
{
	LLI	num;

	num = n;
	write_nbr(num);
}
