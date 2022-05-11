/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:01 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:00 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static uintmax_t	ft_length(t_bin *bin, va_list args)
{
	uintmax_t	u;

	if (bin->length & L_CHAR)
		u = (unsigned char)(va_arg(args, unsigned int));
	else if (bin->length & L_SHORT)
		u = (unsigned short)(va_arg(args, unsigned int));
	else if (bin->length & L_LONG)
		u = (unsigned long)(va_arg(args, unsigned long int));
	else if (bin->length & L_LLONG)
		u = (unsigned long long)(va_arg(args, unsigned long long int));
	else
		u = (unsigned int)(va_arg(args, unsigned int));
	return ((uintmax_t)u);
}

static void	ft_alternate(uintmax_t u, t_bin *bin)
{
	bin->len = ft_strlen(bin->replace);
	if (bin->flags & FLAG_HASH)
	{
		if (!u)
			return ;
		if (bin->conversion == 'x' || bin->conversion == 'X')
			ft_pad_left(&bin->replace, bin->conversion, ++bin->len);
		ft_pad_left(&bin->replace, ZERO, ++bin->len);
	}
}

static void	ft_convert(uintmax_t u, t_bin *bin, const char *base)
{
	if (bin->flags & FLAG_SPACE)
		bin->prefix = ' ';
	if (bin->flags & FLAG_PLUS)
		bin->prefix = '+';
	if (u == 0 && !bin->precision)
		bin->replace = ft_strdup(STR_EMPTY);
	else
		bin->replace = ft_uitoa_base(u, base);
	ft_pad_left(&bin->replace, '0', bin->precision);
	ft_alternate(u, bin);
	if ((bin->flags & FLAG_ZERO) && bin->precision < 0)
	{
		ft_pad_left(&bin->replace, ZERO, bin->width);
		if (bin->width > (int)bin->len && bin->flags & FLAG_HASH && u)
			ft_swap(&bin->replace[1], &bin->replace[bin->width - bin->len + 1]);
	}
	else if (bin->flags & FLAG_MINUS)
		ft_pad_right(&bin->replace, ' ', bin->width);
	else
		ft_pad_left(&bin->replace, ' ', bin->width);
}

void	ft_convert_ux(t_bin *bin, va_list args, const char *b)
{
	uintmax_t	u;

	u = ft_length(bin, args);
	ft_convert(u, bin, b);
	bin->len = ft_strlen(bin->replace);
}
