/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 02:12:23 by seronen           #+#    #+#             */
/*   Updated: 2020/08/18 14:08:59 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			get_targets(t_filler *node)
{
	t_coord	*head;
	int		y;
	int		x;

	if (!(head = (t_coord*)malloc(sizeof(t_coord))))
		return (1);
	head->next = NULL;
	y = 0;
	while (y < node->brd->y - node->piece->y)
	{
		x = 0;
		while (x < node->brd->x - node->piece->x + 1)
		{
			if (check_eloc(node->brd->brd, y, x, node))
				add_coord(head, y, x);
			x++;
		}
		y++;
	}
	node->eloc = head;
	clean_eloc(node, 1);
	return (0);
}

int			parse_eloc(t_filler *node)
{
	t_coord	*tmp;
	t_coord	*etmp;
	int		md;
	int		res;

	tmp = node->loc;
	while (tmp->next)
	{
		etmp = node->eloc;
		md = math(etmp, tmp);
		while (etmp->next)
		{
			res = math(etmp, tmp);
			if (res < md)
				md = res;
			etmp = etmp->next;
		}
		tmp->md = md;
		tmp = tmp->next;
	}
	free_coord(&node->eloc);
	return (0);
}

int			*get_best_place(t_filler *node)
{
	t_coord	*temp;
	int		res;
	int		*ret;

	if (parse_eloc(node))
		return (NULL);
	ret = (int*)malloc(sizeof(int) * 2);
	temp = node->loc;
	res = temp->md;
	ret[0] = temp->y;
	ret[1] = temp->x;
	while (temp->next)
	{
		if (temp->md < res)
		{
			res = temp->md;
			ret[0] = temp->y;
			ret[1] = temp->x;
		}
		temp = temp->next;
	}
	return (ret);
}

int			*get_first(t_filler *node)
{
	int *ret;

	if (!node->loc)
		return (NULL);
	ret = (int*)malloc(sizeof(int) * 2);
	ret[0] = node->loc->y;
	ret[1] = node->loc->x;
	return (ret);
}

int			*algomane(t_filler *node)
{
	int *res;

	get_targets(node);
	if (!node->eloc)
	{
		if (!(res = get_first(node)))
			return (NULL);
		return (res);
	}
	if (!(res = get_best_place(node)))
		return (NULL);
	return (res);
}
