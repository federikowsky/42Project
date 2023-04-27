/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:31:07 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/04/04 17:43:54 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int e_move_w (t_sl *sl)
{
	if (sl->map[sl->enemy_x - 1][sl->enemy_y] == 'C' || sl->map[sl->enemy_x - 1][sl->enemy_y] == 'N')
		return (0);
    if (sl->map[sl->enemy_x - 1][sl->enemy_y] == '1')
	{
		better_y(sl);
		return (0);
	}
	mlx_destroy_image(sl->mlx, sl->enemy);
	sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/oryx_b.xpm",
		&sl->img_w, &sl->img_h);
    sl->map[sl->enemy_x][sl->enemy_y] = '0';
	sl->map[sl->enemy_x - 1][sl->enemy_y] = 'N';
	return (1); 
}

int e_move_a (t_sl *sl)
{
	if (sl->map[sl->enemy_x - 1][sl->enemy_y] == 'C' || sl->map[sl->enemy_x - 1][sl->enemy_y] == 'N')
		return (0);
    if (sl->map[sl->enemy_x][sl->enemy_y - 1] == 'P')
	{
		// move_check2(sl);
		return (0);
	}
	mlx_destroy_image(sl->mlx, sl->enemy);
	sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/oryx_l.xpm",
		&sl->img_w, &sl->img_h);
	sl->map[sl->enemy_x][sl->enemy_y] = '0';
	sl->map[sl->enemy_x][sl->enemy_y - 1] = 'N';
	return (1); 
}

int e_move_s (t_sl *sl)
{
	if (sl->map[sl->enemy_x - 1][sl->enemy_y] == 'C' || sl->map[sl->enemy_x - 1][sl->enemy_y] == 'N')
		return (0);
    if (sl->map[sl->enemy_x + 1][sl->enemy_y] == '1')
	{
		better_y(sl);
		return (0);
	}
	mlx_destroy_image(sl->mlx, sl->enemy);
	sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/oryx_l.xpm",
		&sl->img_w, &sl->img_h);
	sl->map[sl->enemy_x][sl->enemy_y] = '0';
	sl->map[sl->enemy_x + 1][sl->enemy_y] = 'N';
	return (1); 
}

int e_move_d (t_sl *sl)
{
	if (sl->map[sl->enemy_x - 1][sl->enemy_y] == 'C' || sl->map[sl->enemy_x - 1][sl->enemy_y] == 'N')
		return (0);
    if (sl->map[sl->enemy_x][sl->enemy_y + 1] == 'P')
	{
		// move_check2(sl);
		return (0);
	}
	mlx_destroy_image(sl->mlx, sl->enemy);
	sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/oryx_r.xpm",
		&sl->img_w, &sl->img_h);
	sl->map[sl->enemy_x][sl->enemy_y] = '0';
	sl->map[sl->enemy_x][sl->enemy_y + 1] = 'N';
	return (1); 
}

int	better_y(t_sl *sl)
{
	if (sl->enemy_y > sl->ally_y)
	{
		if (sl->map[sl->enemy_x][sl->enemy_y - 1] == '1')
			return (0);
		e_move_a(sl);
		return (1);
	}
	else if (sl->enemy_y < sl->ally_y)
	{
		if (sl->map[sl->enemy_x][sl->enemy_y + 1] == '1')

			return (0);
		e_move_d(sl);
		return (1);
	}
	return(0);
}

int	better_x(t_sl *sl)
{
	if (sl->map[sl->enemy_x + 1][sl->enemy_y] == '1')
	{
		if (sl->map[sl->enemy_x - 1][sl->enemy_y + 1] == '1')
			return (0);
		sl->map[sl->enemy_x][sl->enemy_y] = '0';
		sl->map[sl->enemy_x - 1][sl->enemy_y] = 'N';
		return (1);
	}
	else if (sl->map[sl->enemy_x - 1][sl->enemy_y] == '1')
	{
		if (sl->map[sl->enemy_x + 1][sl->enemy_y] == '1')
			return (0);
		sl->map[sl->enemy_x][sl->enemy_y] = '0';
		sl->map[sl->enemy_x + 1][sl->enemy_y] = 'N';
		return (1);
	}
	return (0);
}

int	move_check2(t_sl *sl)
{
	if (sl->enemy_y > sl->ally_y)
		return (2);
	else if (sl->enemy_y < sl->ally_y)
		return (1);
	else if (sl->enemy_x < sl->ally_x)
		return (4);
	else if (sl->enemy_x > sl->ally_x)
		return (3);
	return(0);
}
