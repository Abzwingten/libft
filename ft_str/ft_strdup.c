/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:26:43 by rantario          #+#    #+#             */
/*   Updated: 2021/10/20 12:20:20 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	void	*new;

	len = ft_strlen (str) + 1;
	new = malloc (len);
	if (new == NULL)
		return (NULL);
	return ((char *) ft_memcpy (new, str, len));
}
