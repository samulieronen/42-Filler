/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:26:22 by seronen           #+#    #+#             */
/*   Updated: 2020/08/18 16:21:29 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_coord
{
	int				x;
	int				y;
	int				md;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_board
{
	char		**brd;
	int			x;
	int			y;
}					t_board;

typedef struct		s_piece
{
	char		**piece;
	t_coord		*crd;
	int			ox;
	int			oy;
	int			x;
	int			y;
}					t_piece;

typedef struct		s_filler
{
	t_board		*brd;
	t_piece		*piece;
	t_coord		*loc;
	t_coord		*eloc;

	int			turnnb;
	int			pnb;
	char		mk;
	char		emk;
}					t_filler;

int					board_len(char *str);
int					count_stars(char **s);
int					defeat_enemy(t_filler *node);
int					get_input(t_filler *node);
int					piece_data(t_filler *node);
t_coord				*alloc_ncoord(int count);
void				free_coord(t_coord **head);
void				clean_eloc(t_filler *node, int code);
int					*algomane(t_filler *node);
int					add_coord(t_coord *head, int y, int x);
int					check_eloc(char **s, int y, int x, t_filler *node);
int					math(t_coord *en, t_coord *me);
#endif
