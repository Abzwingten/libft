/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:04 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:02 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_convert_s(t_bin *bin, va_list args)
{
	char	*tmp;

	tmp = ft_strdup((char *)va_arg(args, char *));
	if (tmp == NULL)
		tmp = STR_NULL;
	if (bin->precision < 0)
		bin->precision = (int)ft_strlen(tmp);
	bin->replace = malloc(bin->precision + 1);
	ft_strlcpy(bin->replace, tmp, bin->precision + 1);
	if (bin->flags & FLAG_MINUS)
		ft_pad_right(&bin->replace, SPACE, bin->width);
	else if (bin->flags & FLAG_ZERO)
		ft_pad_left(&bin->replace, ZERO, bin->width);
	else
		ft_pad_left(&bin->replace, SPACE, bin->width);
	free(tmp);
	bin->len = ft_strlen(bin->replace);
}
