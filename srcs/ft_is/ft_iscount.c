/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:19:34 by rantario          #+#    #+#             */
/*   Updated: 2021/12/30 18:19:35 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iscount(int c, char *base)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			count++;
		i++;
	}
	return (count);
}