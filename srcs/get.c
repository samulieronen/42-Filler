/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:07:41 by seronen           #+#    #+#             */
/*   Updated: 2020/08/18 16:20:42 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_sizes(char *str, int *x, int *y)
{
	char **res;

	if (!(res = ft_strsplit(str, ' ')))
		return (1);
	*y = ft_atoi(res[0]);
	*x = ft_atoi(res[1]);
	free(res[0]);
	free(res[1]);
	free(res);
	return (0);
}

static int		get_piece(t_filler *node, char *info)
{
	int		nb;
	char	*line;

	nb = 0;
	if (get_sizes(&info[5], &node->piece->x, &node->piece->y))
		return (1);
	if (!(node->piece->piece = (char**)malloc(sizeof(char*) *
		node->piece->y + 1)))
		return (1);
	while (get_next_line(0, &line))
	{
		if (line)
		{
			node->piece->piece[nb] = ft_strdup(line);
			nb++;
		}
		ft_strdel(&line);
		if (nb == node->piece->y)
			break ;
	}
	node->piece->piece[nb] = NULL;
	return (0);
}

static int		get_board(t_filler *node, char *info)
{
	int		nb;
	char	*line;

	nb = 0;
	if (get_sizes(&info[7], &node->brd->x, &node->brd->y))
		return (1);
	if (!(node->brd->brd = (char**)malloc(sizeof(char*) * node->brd->y + 1)))
		return (1);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		if (line)
		{
			node->brd->brd[nb] = ft_strdup(&line[4]);
			nb++;
		}
		ft_strdel(&line);
		if (nb == node->brd->y)
			break ;
	}
	node->brd->brd[nb] = NULL;
	return (0);
}

int				get_input(t_filler *node)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (!line)
			return (1);
		else if (line && ft_strstr(line, "Plateau"))
		{
			if (get_board(node, line))
				return (1);
			ft_strdel(&line);
		}
		else if (line && ft_strstr(line, "Piece"))
		{
			if (get_piece(node, line))
				return (1);
			ft_strdel(&line);
			return (0);
		}
		else
			ft_strdel(&line);
	}
	return (1);
}
