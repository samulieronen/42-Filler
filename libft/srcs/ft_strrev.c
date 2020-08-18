/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:10:54 by seronen           #+#    #+#             */
/*   Updated: 2020/02/20 17:43:03 by seronen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	new = (char*)malloc(sizeof(char) * len + 1);
	while (len > 0)
	{
		new[i] = str[len];
		i++;
		len--;
	}
	new[i] = '\0';
	free(str);
	return (new);
}
