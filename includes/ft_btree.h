/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rantario <rantario@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 13:11:38 by rantario          #+#    #+#             */
/*   Updated: 2022/05/11 11:18:32 by rantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	int				*item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;


t_btree				*btree_create_node(void *item);
int					btree_level_count(t_btree *root);
void				btree_add_node(t_btree **root, t_btree *node);
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				*btree_search_item(t_btree *root, void *data_ref, \
											int (*cmpf)(void *, void *));

#endif