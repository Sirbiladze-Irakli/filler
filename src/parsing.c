/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:54:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/08 18:29:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			parse_line(t_filler *fill, char *line)
{
	if (fill->fplateau == 0 && ft_strstr(line, "Plateau"))
		create_map(fill, line);
	else if (fill->fplateau == 1)
		take_map(fill, line);
	else if (fill->fpiece == 0 && ft_strstr(line, "Piece"))
		create_piece(fill, line);
	else if (fill->fpiece == 1)
		take_piece(fill, line);
}

void            create_piece(t_filler *fill, char *line)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	fill->fpiece = 1;
	fill->pheight = ft_atoi(tmp[1]);
	fill->pwidth = ft_atoi(tmp[2]);
	if (!(fill->piece = (char **)malloc(sizeof(char *) * (fill->pheight + 1))))
		output(1);
	while(++i <= fill->pheight)
		if (!(fill->piece[i] = (char *)malloc(sizeof(char)
		* (fill->pwidth + 1))))
			output(1);
	split_free(tmp);
}

void			take_piece(t_filler *fill, char *line)
{
	int		i;

	i = -1;
	if (fill->iterpiece == fill->pheight)
	{
		fill->fpiece = 2;
		return ;
	}
	while (line[++i])
		fill->piece[fill->iterpiece][i] = line[i];
	fill->iterpiece++;
}

void			init_players(t_filler *fill, char **line)
{
	get_next_line(0, line);
	if (!ft_strncmp((*line), "$$$", 2))
	{
		if ((*line)[10] == '1')
		{
			fill->my_num = 1;
			fill->me = "Oo";
			fill->enemy = "Xx";
		}
		else
		{
			fill->my_num = 2;
			fill->enemy = "Oo";
			fill->me = "Xx";
			printf("%c line\n", (*line)[10]);
		}
		printf("%s line\n", (*line));
	}
	free(*line);
}
