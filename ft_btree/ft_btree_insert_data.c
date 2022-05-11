/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:17:25 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 11:22:19 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Inserts the element item into a tree.
** The tree passed as argument will be sorted:
**   - all lower elements are located on the left side
**   - all higher or equal elements on the right.
** The root parameter points to the root node of the tree.
** First time called, it should point to NULL.
*/

void	btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, cmpf);
		else
			node->right = btree_create_node(item);
	}
}
