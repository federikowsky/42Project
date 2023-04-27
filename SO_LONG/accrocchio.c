/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accrocchio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:31:09 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/22 17:56:11 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_game(t_sl *sl)
{
	sl->maps_check = ft_checkmap(sl);
	sl->wall_check = ft_checkwall(sl);
	if (!sl->map || !sl->maps_check || !sl->wall_check)
	{
		ft_printf("errore\n");
		exit(1);
		return (0);
	}
	return (1);
}

void	print_if(t_sl *sl)
{
	sl->y = 0;
	while (sl->y <= sl->colonne)
	{
		if (sl->map[sl->x][sl->y] == '1')
			ft_image(sl, sl->lava, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == '0')
			ft_image(sl, sl->back, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'P')
		{
			sl->ally_x = sl->x;
			sl->ally_y = sl->y;
			ft_image(sl, sl->rogue, sl->x, sl->y);
		}
		else if (sl->map[sl->x][sl->y] == 'E')
			ft_image(sl, sl->exit, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'C')
			ft_image(sl, sl->cons, sl->x, sl->y);
		else if (sl->map[sl->x][sl->y] == 'N')
		{
			sl->enemy_x = sl->x;
			sl->enemy_y = sl->y;
			ft_image(sl, sl->enemy, sl->x, sl->y);
		}
		sl->y += 1;
	}
	sl->x += 1;
}


int	move_check1(t_sl *sl)
{
	if (sl->enemy_x < sl->ally_x)
		return (4);
	else if (sl->enemy_x > sl->ally_x)
		return (3);
	else if (sl->enemy_y > sl->ally_y)
		return (2);
	else if (sl->enemy_y < sl->ally_y)
		return (1);
	return(0);
}

void	enemy_move(t_sl *sl)
{
	sl->enemy_count = move_check1(sl);
	if (sl->enemy_count == 1)
	{
		e_move_d(sl);
	}
	else if (sl->enemy_count == 2)
	{
		e_move_a(sl);
	}
	else if (sl->enemy_count == 3)
	{
		e_move_w(sl);
	}
	else if (sl->enemy_count == 4)
	{
		e_move_s(sl);
	}
}

void	lava_ani(t_sl *sl)
{
mlx_destroy_image(sl->mlx, sl->lava);
if (sl->cont == 0)
{
	sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava2.xpm",
			&sl->img_w, &sl->img_h);
	sl->cont += 1;
}
else if (sl->cont == 1)
{
	sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava.xpm",
			&sl->img_w, &sl->img_h);
	sl->cont = 0;
	}
}