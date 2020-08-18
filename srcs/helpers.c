/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:55:58 by seronen           #+#    #+#             */
/*   Updated: 2020/08/18 14:58:30 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int				count_stars(char **s)
{
	int		i;
	int		k;
	int		sc;

	i = 0;
	sc = 0;
	while (s[i] != NULL)
	{
		k = 0;
		while (s[i][k])
		{
			if (s[i][k] == '*')
				sc++;
			k++;
		}
		i++;
	}
	return (sc);
}

int				math(t_coord *en, t_coord *me)
{
	int res;

	res = (ft_abs(en->x - me->x) + ft_abs(en->y - me->y));
	ft_abs(res);
	return (res);
}

void			clean_eloc(t_filler *node, int code)
{
	t_coord *tmp;

	if (code == 1)
	{
		tmp = node->eloc->next;
		free(node->eloc);
		node->eloc = tmp;
	}
	else
	{
		tmp = node->loc->next;
		free(node->loc);
		node->loc = tmp;
	}
}

void			free_coord(t_coord **head)
{
	t_coord *temp;
	t_coord *tempnext;

	temp = *head;
	while (temp)
	{
		tempnext = temp->next;
		free(temp);
		temp = tempnext;
	}
	*head = NULL;
}

t_coord			*alloc_ncoord(int count)
{
	t_coord		*head;
	t_coord		*tmp;
	int			nb;

	nb = 0;
	if (!(head = (t_coord*)malloc(sizeof(t_coord))))
		return (0);
	nb++;
	count--;
	tmp = head;
	tmp->next = NULL;
	while (count > 0)
	{
		if (!(tmp->next = (t_coord*)malloc(sizeof(t_coord))))
			return (0);
		nb++;
		tmp = tmp->next;
		tmp->next = NULL;
		count--;
	}
	return (head);
}
