/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:05:54 by rantario          #+#    #+#             */
/*   Updated: 2021/10/14 11:15:00 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *s, UI start, size_t len)
{
	char	*neue_s;
	int		i;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		neue_s = (char *) malloc(len + 1);
	else
		neue_s = (char *) malloc(s_len - start + 1);
	if (!neue_s)
		return (NULL);
	i = 0;
	while (start < s_len && len > 0 && s[start + i] != '\0')
	{
		neue_s[i] = s[start + i];
		i++;
		len--;
	}
	neue_s[i] = '\0';
	return (neue_s);
}
