/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:13:47 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/08 18:33:04 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			split_free(char **tmp)
{
	int		i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

void			fill_map(t_filler *fill, char *line, int i, int *j)
{
	while (line[++i])
	{
		if (fill->my_num == 1 && (line[i] == 'O' || line[i] == 'o'))
			fill_me(fill, line, i, j);
		else if (fill->my_num == 1 && (line[i] == 'X' || line[i] == 'x'))
			fill_enemy(fill, line, i, j);
		else if (fill->my_num == 2 && (line[i] == 'O' || line[i] == 'o'))
			fill_enemy(fill, line, i, j);
		else if (fill->my_num == 2 && (line[i] == 'X' || line[i] == 'x'))
			fill_me(fill, line, i, j);
		else
			fill->map[fill->itermap][++(*j)] = line[i];
		printf("%c", fill->map[fill->itermap][(*j)]);
	}
	printf("\n");
}

void			fill_me(t_filler *fill, char *line, int i, int *j)
{
	fill->map[fill->itermap][++(*j)] = line[i];
	fill->my_x = (*j);
	fill->my_y = fill->itermap - 1;
}

void			fill_enemy(t_filler *fill, char *line, int i, int *j)
{
	fill->map[fill->itermap][++(*j)] = line[i];
	fill->enemy_x = (*j);
	fill->enemy_y = fill->itermap - 1;
}
