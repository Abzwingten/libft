/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:06:44 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 21:10:38 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int			get_next_line(int fd, char **line);
// static void	check_n(char **s_buf, char *n, int *ret);
// static void	init_ret_n(int *ret, char **n, int fd, char **line);
// static char	*save_buf(char **s_buf, char **line, int *ret);
// static int	check_error_case(char **s_buf, char **line, int *ret);

char		*ft_strdup_gnl(char *s, int *ret);
char		*ft_strjoin_gnl(char *s1, char *s2, int *ret);
char		*ft_strcpy(char *dest, char *src);

#endif
