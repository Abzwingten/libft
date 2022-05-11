/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_bin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:36 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:35:49 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_place_bin(int fd, t_format *frmt)
{
	t_bin	*bin;

	bin = ft_parser(frmt);
	if (bin->conversion)
	{
		ft_choose_conversion(bin, frmt->args);
		frmt->len += write(fd, bin->replace, bin->len);
		free(bin->replace);
	}
	free(bin);
}
