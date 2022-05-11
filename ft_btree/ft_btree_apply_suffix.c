/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:39:57 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 11:40:03 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function given as argument to the item of each node,
** using suffix traversal to search the tree.
*/

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}