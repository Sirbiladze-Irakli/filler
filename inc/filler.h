/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:11:45 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/06 19:42:55 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define BUFF_SIZE 1
# include "../libft/includes/libft.h"

/*
** main.c
*/

int				main(int ac, char **av);

/*
** get_next_line.c
*/

int				get_next_line(const int fd, char **line);

#endif