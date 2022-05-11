/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:33 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:35:47 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_base_error(const char *base)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(base);
	if (len <= 1)
		return (1);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	ft_digit_counter(uintmax_t n, size_t base_len)
{
	if (!(n / base_len))
		return (1);
	else
		return (ft_digit_counter(n / base_len, base_len) + 1);
}

char	*ft_uitoa_base(uintmax_t n, const char *base)
{
	char	*s;
	size_t	len;
	size_t	base_len;

	if (ft_base_error(base))
		return (NULL);
	base_len = ft_strlen(base);
	len = ft_digit_counter(n, base_len);
	s = malloc((len + 1) * sizeof(*s));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (len--)
	{
		s[len] = base[n % base_len];
		n /= base_len;
	}
	return (s);
}
