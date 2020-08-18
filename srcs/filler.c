/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:47:00 by samulierone       #+#    #+#             */
/*   Updated: 2020/08/18 14:57:40 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int			player_info(t_filler *node)
{
	char *line;

	get_next_line(0, &line);
	if (!line || (line[10] != '1' && line[10] != '2'))
		return (1);
	node->pnb = (line[10] - '0' == 2) ? 2 : 1;
	node->mk = (line[10] - '0' == 2) ? 'X' : 'O';
	node->emk = (line[10] - '0' == 2) ? 'O' : 'X';
	ft_strdel(&line);
	return (0);
}

static t_filler		*init_lists(void)
{
	t_filler *node;

	if (!(node = (t_filler*)malloc(sizeof(t_filler))))
		return (NULL);
	node->turnnb = 0;
	if (!(node->piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	if (!(node->brd = (t_board*)malloc(sizeof(t_board))))
		return (NULL);
	return (node);
}

void				free_all(t_filler *node)
{
	ft_printf("%d %d\n", 0, 0);
	if (node->piece->crd)
		free_coord(&node->piece->crd);
	if (node->loc)
		free_coord(&node->loc);
	if (node->brd->brd)
		ft_2dstrdel(node->brd->brd);
	if (node->piece->piece)
		ft_2dstrdel(node->piece->piece);
	free(node->piece);
	free(node->brd);
	free(node);
}

int					main(void)
{
	t_filler	*node;
	int			ret;

	if (!(node = init_lists()))
		return (1);
	if (player_info(node))
		return (1);
	while (1)
	{
		if ((ret = get_input(node)) > 0)
			break ;
		if ((ret = defeat_enemy(node)) > 0)
			break ;
	}
	free_all(node);
	return (ret);
}
