/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:14:44 by sherbert          #+#    #+#             */
/*   Updated: 2022/01/25 14:50:29 by rantario         ###   ########.fr       */
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
	char		*num;

	*ret = 1;
	num = NULL;
	if (*s_buf)
	{
		num = ft_strchr(*s_buf, '\n');
		if (num)
			*num++ = '\0';
		*line = ft_strdup_gnl(*s_buf, ret);
		if (num)
			ft_strcpy(*s_buf, num);
		else
			save_free(s_buf);
	}
	else
		*line = ft_strdup_gnl("\0", ret);
	return (num);
}

static void	init_ret_n(int *ret, char **num, int fd, char **line)
{
	*num = NULL;
	*ret = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		*ret = -1;
}

static void	check_n(char **s_buf, char *num, int *ret)
{
	save_free(s_buf);
	*s_buf = ft_strdup_gnl(num, ret);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*s_buf = NULL;
	char		*num;
	char		*tmp;
	int			ret;

	init_ret_n(&ret, &num, fd, line);
	if (!ret)
		num = save_buf(&s_buf, line, &ret);
	while (!num && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		num = ft_strchr(buf, '\n');
		if (num)
			check_n(&s_buf, ++num, &ret);
		tmp = *line;
		*line = ft_strjoin_gnl(*line, buf, &ret);
		save_free(&tmp);
	}
	return (check_error_case(&s_buf, line, &ret));
}
