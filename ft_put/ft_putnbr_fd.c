/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:26:14 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 14:54:32 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	write_nbr(long long int num, int fd)
{
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	if (num >= 10)
		write_nbr(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	LLI	num;

	num = n;
	write_nbr(num, fd);
}
