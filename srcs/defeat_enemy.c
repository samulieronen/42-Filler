/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defeat_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:05:39 by seronen           #+#    #+#             */
/*   Updated: 2020/08/18 16:20:54 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_eloc(char **s, int y, int x, t_filler *node)
{
	if ((x + 2) > node->brd->x - 1 || (x - 2) < 0)
		return (0);
	if ((y + 2) > node->brd->y - 1 || (y - 2) < 0)
		return (0);
	if (s[y][x] == node->emk && (s[y][x + 1] == '.' ||
		s[y][x - 1] == '.' || s[y + 1][x] == '.' || s[y - 1][x] == '.'))
	{
		if (s[y][x] == node->emk && (s[y][x + 2] == '.' ||
			s[y][x - 2] == '.' || s[y + 2][x] == '.' || s[y - 2][x] == '.'))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int			check_fit(int py, int px, t_filler *node, t_piece *pc)
{
	t_coord *c;
	char	**map;
	int		hit;
	int		illegal;

	hit = 0;
	illegal = 0;
	c = pc->crd;
	map = node->brd->brd;
	while (c)
	{
		if (py + c->y > node->brd->y || px + c->x > node->brd->x ||
			py + c->y < 0 || px + c->x < 0)
			return (0);
		else if (map[py + c->y][px + c->x] == node->mk)
			hit++;
		else if (map[py + c->y][px + c->x] != '.' &&
			map[py + c->y][px + c->x] != node->mk)
			illegal++;
		c = c->next;
	}
	if (hit == 1 && illegal == 0)
		return (1);
	return (0);
}

int			add_coord(t_coord *head, int y, int x)
{
	t_coord *tmp;
	t_coord *new;

	new = (t_coord*)malloc(sizeof(t_coord));
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	tmp = tmp->next;
	tmp->y = y;
	tmp->x = x;
	tmp->next = NULL;
	return (0);
}

int			parse_board(t_filler *node)
{
	t_coord *head;
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
			if (check_fit(y, x, node, node->piece))
				add_coord(head, y, x);
			x++;
		}
		y++;
	}
	node->loc = head;
	clean_eloc(node, 0);
	return (0);
}

int			defeat_enemy(t_filler *node)
{
	int		*res;

	if (piece_data(node))
		return (1);
	parse_board(node);
	if (!node->loc)
		return (1);
	if (!(res = algomane(node)))
		return (1);
	ft_printf("%d %d\n", res[0] - node->piece->oy, res[1] - node->piece->ox);
	node->turnnb += 1;
	free(res);
	free_coord(&node->loc);
	free_coord(&node->piece->crd);
	ft_2dstrdel(node->brd->brd);
	ft_2dstrdel(node->piece->piece);
	return (0);
}
