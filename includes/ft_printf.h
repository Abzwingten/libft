/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:11:38 by rantario          #+#    #+#             */
/*   Updated: 2022/01/09 13:11:46 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include "libft.h"

# define PLACEHOLDER_FLAGS			"+- 0#"
# define PLACEHOLDER_CONVERSIONS	"cspdiuxX%"

# define MINUS		'-'
# define PLUS		'+'
# define SPACE		' '
# define ZERO		'0'
# define X			'x'

# define WIDTH		0
# define PRECISION	1

# define FLAG_MINUS	1
# define FLAG_PLUS	2
# define FLAG_ZERO 	4
# define FLAG_HASH 	8
# define FLAG_SPACE	16

# define L_CHAR		1
# define L_SHORT	2
# define L_LONG		4
# define L_LLONG	8

# define DEC_BASE	"0123456789"
# define HEX_BASE_L	"0123456789abcdef"
# define HEX_BASE_U	"0123456789ABCDEF"
# define OCT_BASE	"01234567"

# define STR_NULL	"(null)"
# define STR_EMPTY	""
# define PTR_START	"0x"

typedef struct s_bin
{
	char		flags;
	int			width;
	int			precision;
	char		length;
	char		conversion;
	char		prefix;
	char		*replace;
	size_t		len;
}				t_bin;

typedef struct s_format
{
	const char	*input;
	va_list		args;
	int			pos;
	int			len;
}				t_format;

int				ft_printf(const char *format, ...);
int				ft_vdprintf(int fd, const char *format, va_list ap);

t_bin			*ft_bin_initializer(void);
t_bin			*ft_parser(t_format *f);
int				ft_parser_asterix(char option, t_format *f, t_bin *bin);
void			ft_parser_flags(t_format *f, t_bin *bin);
void			ft_parser_width(t_format *f, t_bin *bin);
void			ft_parser_precision(t_format *f, t_bin *bin);
void			ft_parser_length(t_format *f, t_bin *bin);
void			ft_parser_conversion(t_format *f, t_bin *bin);
void			ft_parser_dump(t_bin *bin);

void			ft_convert_pct(t_bin *bin);
void			ft_convert_p(t_bin *bin, va_list args);
void			ft_convert_d(t_bin *bin, va_list args);
void			ft_convert_s(t_bin *bin, va_list args);
void			ft_convert_c(t_bin *bin, va_list args);
void			ft_convert_ux(t_bin *bin, va_list args, const char *base);

t_format		*ft_format_initializer(const char *format, va_list args);
void			ft_place_bin(int fd, t_format *frmt);
void			ft_choose_conversion(t_bin *bin, va_list args);
void			ft_pad_left(char **src, char pad, int width);
void			ft_pad_right(char **src, char pad, int width);
void			ft_prefix(t_bin *bin);
char			*ft_uitoa_base(uintmax_t n, const char *base);

#endif
