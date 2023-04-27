/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:20:54 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/14 19:25:43 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_printwall(t_sl *sl)
{
	sl->lava = mlx_xpm_file_to_image(sl->mlx, "spritexpm/lava.xpm",
			&sl->img_w, &sl->img_h);
}

void	ft_printback(t_sl *sl)
{
	sl->back = mlx_xpm_file_to_image(sl->mlx, "spritexpm/background.xpm",
			&sl->img_w, &sl->img_h);
}

void	ft_printrogue(t_sl *sl)
{
	sl->rogue = mlx_xpm_file_to_image(sl->mlx, "spritexpm/rogue.xpm",
			&sl->img_w, &sl->img_h);
}

void	ft_printexit(t_sl *sl)
{
	sl->exit = mlx_xpm_file_to_image(sl->mlx, "spritexpm/exit.xpm",
			&sl->img_w, &sl->img_h);
}

void	ft_printcons(t_sl *sl)
{
	sl->cons = mlx_xpm_file_to_image(sl->mlx, "spritexpm/white.xpm",
			&sl->img_w, &sl->img_h);
}
