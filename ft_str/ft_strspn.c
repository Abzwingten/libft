/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 20:47:38 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 20:47:42 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t ft_strspn(const char *str, const char *chars)
{
    int count;

    count = 0;
    while (str[count] && ft_strchr(chars, str[count]))
        count++;
    return (count);
}
