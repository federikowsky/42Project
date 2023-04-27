/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:53:47 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/03/23 18:12:24 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkmap(t_sl *sl)
{	
	sl->x = 0;
	sl->map_ally = 0;
	sl->map_coll = 0;
	sl->map_exit = 0;
	while (sl->x < sl->righe)
	{
		sl->y = 0;
		while (sl->y <= sl->colonne)
		{
			if (sl->map[sl->x][sl->y] != '\0' || sl->map[sl->x][sl->y] != '\n' || sl->map[sl->x][sl->y] != 'P' || sl->map[sl->x][sl->y] != '1' || sl->map[sl->x][sl->y] != '0' || sl->map[sl->x][sl->y] != 'E' || sl->map[sl->x][sl->y] != 'N' || sl->map[sl->x][sl->y] != 'C')
				// return (0);
			if (sl->map[sl->x][sl->y] == 'P')
				sl->map_ally += 1;
			if (sl->map[sl->x][sl->y] == 'E')
				sl->map_exit += 1;
			if (sl->map[sl->x][sl->y] == 'C')
				sl->map_coll += 1;
			sl->y += 1;
		}
		sl->x += 1;
	}
	if (sl->map_ally != 1 || sl->map_coll < 1 || sl->map_exit < 1)
		return (0);
	return (1);
}

int	ft_checkwall(t_sl *sl)
{
	sl->x = 0;
	while (sl->x < sl->righe)
	{
		sl->y = 0;
		while (sl->y < sl->colonne)
		{
			if (sl->map[0][sl->y] != '1')
				return (0);
			if (sl->map[sl->righe - 1][sl->y] != '1')
				return (0);
			if (sl->map[sl->x][0] != '1')
				return (0);
			if (sl->map[sl->x][sl->colonne - 1] != '1')
				return (0);
			sl->y += 1;
		}
		sl->x += 1;
	}
	return (1);
}

char	**ft_mapread(char *path, t_sl *sl)
{
	sl->x = 0;
	sl->y = 0;
	sl->righe = 0;
	sl->fd = open(path, O_RDONLY);
	sl->line = get_next_line(sl->fd);
	if (!sl->line)
		return (0);
	sl->colonne = ft_strlen_mod(sl->line);
	ft_check_size(sl);
	sl->fd = close(sl->fd);
	sl->fd = open(path, O_RDONLY);
	sl->line = get_next_line(sl->fd);
	sl->map = malloc(sizeof(char *) * sl->righe);
	while (sl->line)
	{
		sl->map[sl->x] = ft_strdup(sl->line);
		free(sl->line);
		sl->line = get_next_line(sl->fd);
		sl->x++;
	}
	return (sl->map);
}

int	ft_argcheck(char *path)
{
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b'
		|| path[i - 4] != '.')
		return (0);
	return (1);
}

int	ft_check_size(t_sl *sl)
{
	while (sl->line)
	{	
		sl->colonne1 = ft_strlen_mod(sl->line);
		if (sl->colonne != sl->colonne1)
			return (0);
		sl->righe += 1;
		free(sl->line);
		sl->line = get_next_line(sl->fd);
	}
	return (1);
}
