/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw_patrol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:16:07 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 16:34:54 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_draw_death(t_check pos, char *map[], mlx_t *wind, mlx_image_t ***img)
{
	int	x;
	int	y;

	x = pos.x;
	y = pos.y;
	if (map[y][x - 1] == '0')
	{
		pos.x -= 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
		pos.x += 1;
	}
	if (map[y][x + 1] == '0')
	{
		pos.x += 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
		pos.x -= 1;
	}
	if (map[y - 1][x] == '0')
	{
		pos.y -= 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
		pos.y += 1;
	}
	if (map[y + 1][x] == '0')
	{
		pos.y += 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
		pos.y -= 1;
	}
	return (ft_redraw_pos(pos, wind, "tombstone.png", img));
}

static int	ft_draw_right(t_check pos, char *map[], mlx_t *wind, mlx_image_t ***img)
{
	int	i;
	int	j;

	i = pos.y;
	j = pos.x;
	if (map[i][j - 1] != '1' && map[i][j - 1] != 'R'
			&& map[i][j - 1] != 'C' && map[i][j - 1] != 'E'
			&& map[i][j - 1] != 'L')
	{
		pos.x -= 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
	}
	return (1);
}

static int	ft_draw_left(t_check pos, char *map[], mlx_t *wind, mlx_image_t ***img)
{
	int	i;
	int	j;

	i = pos.y;
	j = pos.x;
	if (map[i][j + 1] != '1' && map[i][j + 1] != 'R'
			&& map[i][j + 1] != 'C' && map[i][j + 1] != 'E'
			&& map[i][j + 1] != 'L')
	{
		pos.x += 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) < 0)
			return (-1);
	}
	return (1);
}

int	ft_redraw_patrol(mlx_t *wind, char *map[], mlx_image_t ***img)
{
	int		i;
	int		j;
	t_check	pos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			pos.x = j;
			pos.y = i;
			if (map[i][j] == 'R' && ft_draw_right(pos, map, wind, img) == -1)
				return (-1);
			if (map[i][j] == 'L' && ft_draw_left(pos, map, wind, img) == -1)
				return (-1);
			if (map[i][j] == 'D' && ft_draw_death(pos, map, wind, img) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
