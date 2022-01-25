/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:20 by rantario          #+#    #+#             */
/*   Updated: 2022/01/25 13:40:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

int	ft_nbr_len(int num)
{
	int	digits;

	digits = 1;
	if (num < 0)
	{
		digits++;
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int num)
{
	char	*str;
	int		i;
	int		len;
	int		const_len;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_len(num);
	const_len = len;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
		i++;
		len--;
	}
	while (i < const_len)
		str[i++] = (num / ft_div(len--) % 10) + 48;
	str[i] = '\0';
	return (str);
}
