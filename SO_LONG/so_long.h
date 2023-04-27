/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:39:56 by aannunzi          #+#    #+#             */
/*   Updated: 2022/03/23 18:07:45 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "print_f/ft_printf.h"

typedef struct sl
{
	char	**map;
	char	*line;
	void	*mlx;
	void	*mlx_win;
	void	*lava;
	void	*over;
	void	*back;
	void	*rogue;
	void	*exit;
	void	*cons;
	void	*enemy;
	int		img_w;
	int		img_h;
	int		ally_x;
	int		ally_y;
	int		enemy_x;
	int		enemy_y;
	int		oldenemy_x;
	int		oldenemy_y;
	int		map_wall;
	int		map_exit;
	int		map_coll;
	int		map_ally;
	int		x;
	int		y;
	int		cont;
	int		loop;
	int		cont2;
	int		loop2;
	int		move;
	int		colonne;
	int		colonne1;
	int		righe;
	int		fd;
	int		maps_check;
	int		wall_check;
	int		arg_check;
	int		bho;
	int		moves;
	int		enemy_count;
	int		bho2;
}				t_sl;

void	ft_printwall(t_sl *sl);
void	ft_printback(t_sl *sl);
void	ft_printrogue(t_sl *sl);
void	ft_printexit(t_sl *sl);
void	ft_printcons(t_sl *sl);
void	ft_printenemy(t_sl *sl);
int		move_w(t_sl *sl);
int		move_a(t_sl *sl);
int		move_s(t_sl *sl);
int		move_d(t_sl *sl);
void	ft_initimage(t_sl *sl);
void	lava_ani(t_sl *sl);
char	**ft_mapread(char *path, t_sl *sl);
int		ft_checkmap(t_sl *sl);
void	ft_freemap(char **map);
size_t	ft_strlen_mod(const char *s);
char	*ft_strdup(const char *s1);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_checkwall(t_sl *sl);
size_t	get_digits(int n);
char	*ft_itoa(int n);
int		exit_loop(t_sl *sl);
int		ft_quit(t_sl *sl);
int		ft_argcheck(char *path);
void	ft_image(t_sl *sl, void *image, int x, int y);
void	ft_printmap(t_sl *sl);
void		exit_if(t_sl *sl);
int		check_game(t_sl *sl);
void	print_if(t_sl *sl);
int		ft_dead(t_sl *sl);
int		ft_check_size(t_sl *sl);
int		ft_end(t_sl *sl);
int		loop(t_sl *sl);
void	enemy_move(t_sl *sl);
int		e_move_w (t_sl *sl);
int		e_move_a (t_sl *sl);
int		e_move_s (t_sl *sl);
int		e_move_d (t_sl *sl);
int	better_y(t_sl *sl);
int	better_x(t_sl *sl);
int	move_check2(t_sl *sl);
#endif