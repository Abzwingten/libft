/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:52 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:35:54 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parser_flags(t_format *f, t_bin *bin)
{
	if (!f->input[f->pos])
		return ;
	while (ft_strchr(PLACEHOLDER_FLAGS, f->input[f->pos]))
	{
		if (f->input[f->pos] == '-')
			bin->flags |= FLAG_MINUS;
		else if (f->input[f->pos] == '0')
			bin->flags |= FLAG_ZERO;
		else if (f->input[f->pos] == '+')
			bin->flags |= FLAG_PLUS;
		else if (f->input[f->pos] == '#')
			bin->flags |= FLAG_HASH;
		else if (f->input[f->pos] == ' ')
			bin->flags |= FLAG_SPACE;
		f->pos++;
	}
}

void	ft_parser_width(t_format *f, t_bin *bin)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == '*')
	{
		bin->width = ft_parser_asterix(FT_WIDTH, f, bin);
		f->pos++;
	}
	else
	{
		bin->width = ft_atoi(f->input + f->pos);
		while (ft_isdigit(f->input[f->pos]))
			f->pos++;
	}
}

void	ft_parser_precision(t_format *f, t_bin *bin)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == '.')
	{
		f->pos++;
		if (f->input[f->pos] == '*')
		{
			bin->precision = ft_parser_asterix(PRECISION, f, bin);
			f->pos++;
		}
		else
		{
			if (!ft_isdigit(f->input[f->pos]))
				bin->precision = 0;
			else
				bin->precision = ft_atoi(f->input + f->pos);
			while (ft_isdigit(f->input[f->pos]))
				f->pos++;
		}
	}
}

void	ft_parser_length(t_format *f, t_bin *bin)
{
	if (!f->input[f->pos])
		return ;
	if (f->input[f->pos] == 'h')
	{
		bin->length |= L_SHORT;
		f->pos++;
		if (f->input[f->pos] == 'h')
		{
			bin->length |= L_CHAR;
			f->pos++;
		}
	}
	else if (f->input[f->pos] == 'l')
	{
		bin->length |= L_LONG;
		f->pos++;
		if (f->input[f->pos] == 'l')
		{
			bin->length |= L_LLONG;
			f->pos++;
		}
	}
}

void	ft_parser_conversion(t_format *f, t_bin *bin)
{
	int		i;
	int		len;
	char	*conversions;

	if (!f->input[f->pos])
		return ;
	i = 0;
	len = ft_strlen(PLACEHOLDER_CONVERSIONS);
	conversions = ft_strdup(PLACEHOLDER_CONVERSIONS);
	while (i < len)
	{
		if (f->input[f->pos] == conversions[i])
			bin->conversion = conversions[i];
		i++;
	}
	free(conversions);
	f->pos++;
}
