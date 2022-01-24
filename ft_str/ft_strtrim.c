/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:31:35 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/07 19:24:47 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	size_t	left;
	size_t	right;
	char	*str;

	str = NULL;
	if (s1 && set)
	{
		left = 0;
		right = ft_strlen(s1);
		while (s1[left] && ft_strchr(set, s1[left]))
			left++;
		while (right > left && ft_strchr(set, s1[right - 1]))
			right--;
		str = (char *) malloc(right - left + 1);
		if (str)
			ft_strlcpy(str, &s1[left], right - left + 1);
	}
	return (str);
}
