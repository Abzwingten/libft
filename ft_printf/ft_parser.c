/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:39 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 17:35:51 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bin	*ft_parser(t_format *frmt)
{
	t_bin	*bin;

	bin = ft_bin_initializer();
	frmt->pos++;
	ft_parser_flags(frmt, bin);
	ft_parser_width(frmt, bin);
	ft_parser_precision(frmt, bin);
	ft_parser_length(frmt, bin);
	ft_parser_conversion(frmt, bin);
	return (bin);
}
