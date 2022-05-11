/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:17:25 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 11:33:14 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the size of the largest branch passed as argument.
*/

int	btree_level_count(t_btree *root)
{
	if (root)
		return (1 + ft_max(btree_level_count(root->left), \
				btree_level_count(root->right)));
	else
		return (0);
}