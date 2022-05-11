/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:23 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:09 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t	ft_length(t_bin *bin, va_list args)
{
	intmax_t	d;

	if (bin->length & L_CHAR)
		d = (char)(va_arg(args, int));
	else if (bin->length & L_SHORT)
		d = (short)(va_arg(args, int));
	else if (bin->length & L_LONG)
		d = (long)(va_arg(args, long int));
	else if (bin->length & L_LLONG)
		d = (long long)(va_arg(args, long long int));
	else
		d = (int)(va_arg(args, int));
	return ((intmax_t)d);
}

static void	ft_convert(intmax_t d, t_bin *bin)
{
	if (bin->flags & FLAG_SPACE)
		bin->prefix = ' ';
	if (bin->flags & FLAG_PLUS)
		bin->prefix = '+';
	if (d == 0 && !bin->precision)
		bin->replace = ft_strdup(STR_EMPTY);
	else
	{
		if (d < 0)
		{
			bin->prefix = MINUS;
			d = (uintmax_t)(d * -1);
		}
		bin->replace = ft_uitoa_base(d, DEC_BASE);
	}
}

static void	ft_pad(t_bin *bin)
{
	ft_pad_left(&bin->replace, '0', bin->precision);
	if (bin->prefix)
		bin->width--;
	if (bin->flags & FLAG_MINUS)
		ft_pad_right(&bin->replace, ' ', bin->width);
	else if ((bin->flags & FLAG_ZERO) && bin->precision < 0)
		ft_pad_left(&bin->replace, '0', bin->width);
	ft_prefix(bin);
	if (bin->prefix)
		bin->width++;
	ft_pad_left(&bin->replace, ' ', bin->width);
}

void	ft_convert_d(t_bin *bin, va_list args)
{
	intmax_t	d;

	d = ft_length(bin, args);
	ft_convert(d, bin);
	ft_pad(bin);
	bin->len = ft_strlen(bin->replace);
}
