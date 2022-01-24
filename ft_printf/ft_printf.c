/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:13:26 by rantario          #+#    #+#             */
/*   Updated: 2022/01/10 15:23:41 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (len);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	int			len;
	t_format	*frmt;

	frmt = ft_format_initializer(format, args);
	while (frmt->input[frmt->pos])
	{
		if (frmt->input[frmt->pos] == '%')
			ft_place_bin(fd, frmt);
		else
		{
			ft_putchar_fd(frmt->input[frmt->pos], fd);
			frmt->len++;
			frmt->pos++;
		}
	}
	len = frmt->len;
	va_end(frmt->args);
	free(frmt);
	return (len);
}
