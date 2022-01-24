/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:20 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:07 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_convert(t_bin *bin, void *p)
{
	if (!p)
	{
		if (!bin->precision)
			bin->replace = ft_strdup(STR_EMPTY);
		else
			bin->replace = ft_strdup("0");
	}
	else
		bin->replace = ft_uitoa_base((uintptr_t)p, HEX_BASE_L);
	bin->len = ft_strlen(bin->replace);
	if (bin->precision > (int)bin->len)
		bin->len = bin->precision;
	ft_pad_left(&bin->replace, ZERO, bin->len);
	ft_pad_left(&bin->replace, X, ++bin->len);
	ft_pad_left(&bin->replace, ZERO, ++bin->len);
	if (bin->flags & FLAG_MINUS)
		ft_pad_right(&bin->replace, SPACE, bin->width);
	else
		ft_pad_left(&bin->replace, SPACE, bin->width);
}

void	ft_convert_p(t_bin *bin, va_list args)
{
	void	*p;

	p = va_arg(args, void *);
	ft_convert(bin, p);
	bin->len = ft_strlen(bin->replace);
}
