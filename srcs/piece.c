/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:49:53 by seronen           #+#    #+#             */
/*   Updated: 2020/08/17 19:36:26 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			get_origo(t_filler *node)
{
	char	**str;
	int		x;
	int		y;

	str = node->piece->piece;
	y = 0;
	if (!str)
		return (1);
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == '*')
			{
				node->piece->ox = x;
				node->piece->oy = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int			mod_coord(t_coord *crd, t_filler *node)
{
	t_coord *tmp;

	tmp = crd;
	if (get_origo(node))
		return (1);
	tmp->x = 0;
	tmp->y = 0;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->x -= node->piece->ox;
		tmp->y -= node->piece->oy;
		tmp = tmp->next;
	}
	return (0);
}

static int			update_bounds(t_piece *pc)
{
	t_coord		*cd;
	int			maxx;
	int			maxy;

	cd = pc->crd;
	maxx = cd->x;
	maxy = cd->y;
	cd = cd->next;
	while (cd)
	{
		if (maxx < cd->x)
			maxx = cd->x;
		if (maxy < cd->y)
			maxy = cd->y;
		cd = cd->next;
	}
	pc->x = maxx;
	pc->y = maxy;
	return (0);
}

static int			make_coords(t_piece *pc)
{
	t_coord		*tmp;
	int			x;
	int			y;

	y = 0;
	pc->crd = alloc_ncoord(count_stars(pc->piece));
	tmp = pc->crd;
	while (y < pc->y)
	{
		x = 0;
		while (x < pc->x)
		{
			if (pc->piece[y][x] == '*')
			{
				tmp->x = x;
				tmp->y = y;
				tmp = tmp->next;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int					piece_data(t_filler *node)
{
	if (make_coords(node->piece))
		return (1);
	if (mod_coord(node->piece->crd, node))
		return (1);
	update_bounds(node->piece);
	return (0);
}
