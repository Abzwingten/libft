/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 21:35:52 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 20:50:35 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *s1, char *s2)
{
	char	*result;
	int		i[2];

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	result = ft_strnew(ft_strlen(s2) + ft_strlen(s1) + 1);
	i[0] = 0;
	while (s1[i[0]])
	{
		result[i[0]] = s1[i[0]];
		i[0]++;
	}
	i[1] = 0;
	while (s2[i[1]])
	{
		result[i[0]] = s2[i[1]];
		i[0]++;
		i[1]++;
	}
	result[i[0]] = '\0';
	return (result);
}
