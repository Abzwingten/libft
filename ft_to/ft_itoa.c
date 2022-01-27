/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:20 by rantario          #+#    #+#             */
/*   Updated: 2021/10/20 14:54:52 by rantario         ###   ########.fr       */
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

int	ft_nbr_len(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	int		const_len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nbr_len(n);
	const_len = len;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		i++;
		len--;
	}
	while (i < const_len)
		str[i++] = (n / ft_div(len--) % 10) + 48;
	str[i] = '\0';
	return (str);
}
