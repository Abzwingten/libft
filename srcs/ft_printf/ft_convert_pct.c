/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:14:08 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:36:04 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_convert_pct(t_bin *bin)
{
	bin->replace = ft_strdup("%");
	if (!bin->width)
		bin->width++;
	if (bin->flags & FLAG_MINUS)
		ft_pad_right(&bin->replace, SPACE, bin->width);
	else if (bin->flags & FLAG_ZERO)
		ft_pad_left(&bin->replace, ZERO, bin->width);
	else
		ft_pad_left(&bin->replace, SPACE, bin->width);
	bin->len = ft_strlen(bin->replace);
}
