/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:17:25 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 11:17:41 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_add_node(t_btree **root, t_btree *node)
{
	t_btree		*tmp;

	tmp = *root;
	if (tmp == NULL)
	{
		tmp = node;
		*root = tmp;
	}
	else if (node->item < tmp->item)
		btree_add_node(&(tmp->left), node);
	else if (node->item > tmp->item)
		btree_add_node(&(tmp->right), node);
}