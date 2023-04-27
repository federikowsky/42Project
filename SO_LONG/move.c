/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:26:01 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/04/08 19:03:33 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_w(t_sl *sl)
{
	if (sl->map_coll == 0 && sl->map[sl->ally_x - 1][sl->ally_y] == 'E')
	{
		sl->map[sl->ally_x][sl->ally_y] = '0';
		sl->move += 1;
		return (2);
	}
	else if (sl->map[sl->ally_x - 1][sl->ally_y] == '1' ||
		sl->map[sl->ally_x - 1][sl->ally_y] == 'E')
		return (3);
	else if (sl->map[sl->ally_x - 1][sl->ally_y] == 'N')
	{
		ft_dead(sl);
		return (4);
	}
	else if (sl->map[sl->ally_x - 1][sl->ally_y] == 'C')
		sl->map_coll -= 1;
	mlx_destroy_image(sl->mlx, sl->rogue);
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogueb.xpm",
			&sl->img_w, &sl->img_h);
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x - 1][sl->ally_y] = 'P';
	sl->move += 1;
	ft_printf("%d\n", sl->move);
	return (1);
}

int	move_a(t_sl *sl)
{
	if (sl->map_coll == 0 && sl->map[sl->ally_x][sl->ally_y - 1] == 'E')
	{
		sl->map[sl->ally_x][sl->ally_y] = '0';
		sl->move += 1;
		return (2);
	}
	else if (sl->map[sl->ally_x][sl->ally_y - 1] == '1' ||
		sl->map[sl->ally_x][sl->ally_y - 1] == 'E')
		return (3);
	else if (sl->map[sl->ally_x][sl->ally_y - 1] == 'N')
	{
		ft_dead(sl);
		return (4);
	}
	else if (sl->map[sl->ally_x][sl->ally_y - 1] == 'C')
		sl->map_coll -= 1;
	mlx_destroy_image(sl->mlx, sl->rogue);
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogue2.xpm",
			&sl->img_w, &sl->img_h);
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x][sl->ally_y - 1] = 'P';
	sl->move += 1;
	ft_printf("%d\n", sl->move);
	return (1);
}

int	move_s(t_sl *sl)
{
	if (sl->map_coll == 0 && sl->map[sl->ally_x + 1][sl->ally_y] == 'E')
	{
		sl->map[sl->ally_x][sl->ally_y] = '0';
		sl->move += 1;
		return (2);
	}
	else if (sl->map[sl->ally_x + 1][sl->ally_y] == '1' ||
		sl->map[sl->ally_x + 1][sl->ally_y] == 'E')
		return (3);
	else if (sl->map[sl->ally_x + 1][sl->ally_y] == 'N')
	{
		ft_dead(sl);
		return (4);
	}
	else if (sl->map[sl->ally_x + 1][sl->ally_y] == 'C')
		sl->map_coll -= 1;
	mlx_destroy_image(sl->mlx, sl->rogue);
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogue.xpm",
			&sl->img_w, &sl->img_h);
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x + 1][sl->ally_y] = 'P';
	sl->move += 1;
	ft_printf("%d\n", sl->move);
	return (1);
}

int	move_d(t_sl *sl)
{
	if (sl->map_coll == 0 && sl->map[sl->ally_x][sl->ally_y + 1] == 'E')
	{
		sl->map[sl->ally_x][sl->ally_y] = '0';
		sl->move += 1;
		return (2);
	}
	else if (sl->map[sl->ally_x][sl->ally_y + 1] == '1' ||
		sl->map[sl->ally_x][sl->ally_y + 1] == 'E')
		return (3);
	else if (sl->map[sl->ally_x][sl->ally_y + 1] == 'N')
	{
		ft_dead(sl);
		return (4);
	}
	else if (sl->map[sl->ally_x][sl->ally_y + 1] == 'C')
		sl->map_coll -= 1;
	mlx_destroy_image(sl->mlx, sl->rogue);
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogue.xpm",
			&sl->img_w, &sl->img_h);
	sl->map[sl->ally_x][sl->ally_y] = '0';
	sl->map[sl->ally_x][sl->ally_y + 1] = 'P';
	sl->move += 1;
	ft_printf("%d\n", sl->move);
	return (1);
}
