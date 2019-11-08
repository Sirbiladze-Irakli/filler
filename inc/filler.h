/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:11:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/08 18:10:08 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 1
# include <stdio.h>
# include "../libft/includes/libft.h"

typedef	struct	s_filler
{
	char		**map;
	char		**piece;
	int			itermap;
	int			height;
	int			width;
	int			fplateau;
	int			fpiece;
	int			pheight;
	int			pwidth;
	int			iterpiece;
	int			my_num;
	int			enemy_x;
	int			enemy_y;
	int			my_x;
	int			my_y;
	char		*me;
	char		*enemy;
}				t_filler;

/*
** main.c
*/

int				main(int ac, char **av);
void			struct_init(t_filler *fill);
void			create_map(t_filler *fill, char *line);
void			take_map(t_filler *fill, char *line);
void			output(int var);

/*
** get_next_line.c
*/

int				get_next_line(const int fd, char **line);

/*
** parsing.c
*/

void			parse_line(t_filler *fill, char *line);
void            create_piece(t_filler *fill, char *line);
void			take_piece(t_filler *fill, char *line);
void			init_players(t_filler *fill, char **line);

/*
** tools.c
*/

void			split_free(char **tmp);
void			fill_map(t_filler *fill, char *line, int i, int *j);
void			fill_me(t_filler *fill, char *line, int i, int *j);
void			fill_enemy(t_filler *fill, char *line, int i, int *j);

/*
** solution.c
*/

void            solution(t_filler *fill);
void			heat_map(t_filler *fill);

#endif