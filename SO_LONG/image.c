/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:24:03 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/21 16:38:32 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_quit(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->mlx_win);
	exit(0);
	return (0);
}

int	exit_loop(t_sl *sl)
{
	mlx_destroy_image(sl->mlx, sl->exit);
	if (sl->cont2 == 0)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont2 += 1;
	}
	else if (sl->cont2 == 1)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit2.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont2 += 1;
	}
	else
		exit_if(sl);
	return (0);
}

void	exit_if(t_sl *sl)
{
	if (sl->cont2 == 2)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit3.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont2 += 1;
	}
	else if (sl->cont2 == 3)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit4.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont2 += 1;
	}
	else if (sl->cont2 == 4)
	{
		sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit5.xpm",
				&sl->img_w, &sl->img_h);
		sl->cont2 = 0;
	}
}

void	ft_initimage(t_sl *sl)
{
	ft_printwall(sl);
	ft_printback(sl);
	ft_printrogue(sl);
	ft_printexit(sl);
	ft_printcons(sl);
	ft_printenemy(sl);
}

void	ft_printenemy(t_sl *sl)
{
	sl->enemy = mlx_xpm_file_to_image(sl->mlx, "spritexpm/oryx_l.xpm",
			&sl->img_w, &sl->img_h);
}
