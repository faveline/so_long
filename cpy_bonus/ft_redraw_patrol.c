/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw_patrol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:16:07 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 09:43:52 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_draw_death(int y, int x, char *map[], mlx_t *wind)
{
	if (map[y][x - 1] == '0')
	{
		if (ft_redraw_pos(x - 1, y, wind, "background.png") < 0)
			return (-1);
	}
	if (map[y][x + 1] == '0')
	{
		if (ft_redraw_pos(x + 1, y, wind, "background.png") < 0)
			return (-1);
	}
	if (map[y - 1][x] == '0')
	{
		if (ft_redraw_pos(x, y - 1, wind, "background.png") < 0)
			return (-1);
	}
	if (map[y + 1][x] == '0')
	{
		if (ft_redraw_pos(x, y + 1, wind, "background.png") < 0)
			return (-1);
	}
	return (ft_redraw_pos(x, y, wind, "tombstone.png"));
}

static int	ft_draw_right(int i, int j, char *map[], mlx_t *wind)
{
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'R'
			&& map[i][j - 1] != 'C' && map[i][j - 1] != 'E'
			&& map[i][j - 1] != 'L')
	{
		if (ft_redraw_pos(j - 1, i, wind, "background.png") < 0)
			return (-1);
	}
	return (1);
}

static int	ft_draw_left(int i, int j, char *map[], mlx_t *wind)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'R'
			&& map[i][j + 1] != 'C' && map[i][j + 1] != 'E'
			&& map[i][j + 1] != 'L')
	{
		if (ft_redraw_pos(j + 1, i, wind, "background.png") < 0)
			return (-1);
	}
	return (1);
}

int	ft_redraw_patrol(mlx_t *wind, char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'R' && ft_draw_right(i, j, map, wind) == -1)
				return (-1);
			if (map[i][j] == 'L' && ft_draw_left(i, j, map, wind) == -1)
				return (-1);
			if (map[i][j] == 'D' && ft_draw_death(i, j, map, wind) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
