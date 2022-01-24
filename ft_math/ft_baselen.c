/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baselen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:10:27 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 18:13:15 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_baselen(long num, int base)
{
	int		size;

	size = 0;
	if (base < 2)
		return (0);
	if (num == 0)
		return (1);
	if (num < 0)
		size++;
	while (num != 0)
	{
		num = num / base;
		size++;
	}
	return (size);
}
