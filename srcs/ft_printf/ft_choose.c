/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:31 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_choose_conversion(t_bin *bin, va_list args)
{
	if (bin->conversion == 'd' || bin->conversion == 'i')
		ft_convert_d(bin, args);
	else if (bin->conversion == 'u')
		ft_convert_ux(bin, args, DEC_BASE);
	else if (bin->conversion == 'x')
		ft_convert_ux(bin, args, HEX_BASE_L);
	else if (bin->conversion == 'X')
		ft_convert_ux(bin, args, HEX_BASE_U);
	else if (bin->conversion == 's')
		ft_convert_s(bin, args);
	else if (bin->conversion == 'c')
		ft_convert_c(bin, args);
	else if (bin->conversion == 'p')
		ft_convert_p(bin, args);
	else if (bin->conversion == '%')
		ft_convert_pct(bin);
}

void	ft_pad_left(char **src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*src);
	if (width < (int)len || !width)
		width = len;
	tmp = malloc(width + 1);
	if (!tmp)
		return ;
	ft_memset(tmp, pad, width - len);
	tmp[width - len] = '\0';
	ft_strlcat(tmp, *src, width + 1);
	free(*src);
	*src = tmp;
}

void	ft_pad_right(char **src, char pad, int width)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*src);
	if (width < (int)len || !width)
		width = len;
	tmp = malloc(width + 1);
	if (!tmp)
		return ;
	ft_strlcpy(tmp, *src, len + 1);
	ft_memset(tmp + len, pad, width - len);
	tmp[width] = '\0';
	free(*src);
	*src = tmp;
}

void	ft_prefix(t_bin *bin)
{
	int	len;

	if (bin->prefix)
	{
		len = (int)ft_strlen(bin->replace) + 1;
		ft_pad_left(&bin->replace, bin->prefix, len);
	}
}
