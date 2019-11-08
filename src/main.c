/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:12:46 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/08 18:22:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			create_map(t_filler *fill, char *line)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_strsplit(line, ' ');
	fill->fplateau = 1;
	fill->height = ft_atoi(tmp[1]);
	fill->width = ft_atoi(tmp[2]);
	if (!(fill->map = (char **)malloc(sizeof(char *) * (fill->height + 1))))
		output(1);
	while (++i <= fill->height)
		if (!(fill->map[i] = (char *)malloc(sizeof(char) * (fill->width + 1))))
			output(1);
	split_free(tmp);
}

void			take_map(t_filler *fill, char *line)
{
	int		i;
	int		j;

	i = 3;
	j = -1;
	fill->itermap++;
	if (ft_strstr(line, "012345"))
		return ;
	fill_map(fill, line, i, &j);
	if (fill->itermap == fill->height)
	{
		fill->fplateau = 2;
		return ;
	}
}

void			output(int var)
{
	if (var == 1)
		write(1, "Memory was not allocated\n", 25);
	exit(0);
}

void			struct_init(t_filler *fill)
{
	fill->itermap = -1;
	fill->height = 0;
	fill->width = 0;
	fill->fplateau = 0;
	fill->fpiece = 0;
	fill->iterpiece = 0;
	fill->pheight = 0;
	fill->pwidth = 0;
	fill->enemy_x = 0;
	fill->enemy_y = 0;
	fill->my_x = 0;
	fill->my_y = 0;
	fill->my_num = 0;
}

int         	main(int ac, char **av)
{
	t_filler	fill;
	char		*line;
	
	struct_init(&fill);
	init_players(&fill, &line);
	while (get_next_line(0, &line) != 0)
	{
		parse_line(&fill, line);
		free(line);
	}
	printf("%d enemy x, %d enemy y\n", fill.enemy_x, fill.enemy_y);
	printf("%d my x, %d my y\n", fill.my_x, fill.my_y);
	// solution(&fill);
	exit (0);
}
