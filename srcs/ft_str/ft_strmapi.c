/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:06:15 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 20:00:06 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*n_s;
	size_t	i;

	if (!s)
		return (NULL);
	n_s = malloc(ft_strlen(s) + 1);
	if (!n_s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n_s[i] = (*f)(i, s[i]);
		i++;
	}
	n_s[i] = '\0';
	return (n_s);
}
