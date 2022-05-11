/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:06:28 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 22:16:56 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strequ(char const *s1, char const *s2)
// {
// 	if (s1 && s2)
// 		if (!ft_strcmp(s1, s2))
// 			return (1);
// 	return (0);
// }

int	ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
		return (ft_strcmp(s1, s2));
	return (0);
}
