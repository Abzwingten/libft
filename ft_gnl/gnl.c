/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:14:44 by sherbert          #+#    #+#             */
/*   Updated: 2021/12/30 21:40:02 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

static int	check_error_case(char **s_buf, char **line, int *ret)
{
	if (*ret <= 0)
	{
		save_free(s_buf);
		if (*ret == -1)
			save_free(line);
		return (*ret);
	}
	return (1);
}

static char	*save_buf(char **s_buf, char **line, int *ret)
{
	char		*n;

	*ret = 1;
	n = NULL;
	if (*s_buf)
	{
		n = ft_strchr(*s_buf, '\n');
		if (n)
			*n++ = '\0';
		*line = ft_strdup_gnl(*s_buf, ret);
		if (n)
			ft_strcpy(*s_buf, n);
		else
			save_free(s_buf);
	}
	else
		*line = ft_strdup_gnl("\0", ret);
	return (n);
}

static void	init_ret_n(int *ret, char **n, int fd, char **line)
{
	*n = NULL;
	*ret = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		*ret = -1;
}

static void	check_n(char **s_buf, char *n, int *ret)
{
	save_free(s_buf);
	*s_buf = ft_strdup_gnl(n, ret);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*s_buf = NULL;
	char		*n;
	char		*tmp;
	int			ret;

	init_ret_n(&ret, &n, fd, line);
	if (!ret)
		n = save_buf(&s_buf, line, &ret);
	while (!n && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		n = ft_strchr(buf, '\n');
		if (n)
			check_n(&s_buf, ++n, &ret);
		tmp = *line;
		*line = ft_strjoin_gnl(*line, buf, &ret);
		save_free(&tmp);
	}
	return (check_error_case(&s_buf, line, &ret));
}
