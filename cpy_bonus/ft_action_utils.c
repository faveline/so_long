/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:18 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 17:06:48 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_if_c(char *map[])
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_w_pressed(char *map[], mlx_t *wind)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos.y - 1][pos.x] != '1' && map[pos.y - 1][pos.x] != 'E'
			&& map[pos.y - 1][pos.x] != 'L' && map[pos.y - 1][pos.x] != 'R')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y - 1][pos.x] = 'P';
		ft_moving_patrol(map);
		return (1);
	}
	if (map[pos.y - 1][pos.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos.y][pos.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_d_pressed(char *map[], mlx_t *wind)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos.y][pos.x + 1] != '1' && map[pos.y][pos.x + 1] != 'E'
			&& map[pos.y][pos.x + 1] != 'L' && map[pos.y][pos.x + 1] != 'R')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y][pos.x + 1] = 'P';
		ft_moving_patrol(map);
		return (1);
	}
	if (map[pos.y][pos.x + 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos.y][pos.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_a_pressed(char *map[], mlx_t *wind)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos.y][pos.x - 1] != '1' && map[pos.y][pos.x - 1] != 'E'
			&& map[pos.y][pos.x - 1] != 'L' && map[pos.y][pos.x - 1] != 'R')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y][pos.x - 1] = 'P';
		ft_moving_patrol(map);
		return (1);
	}
	if (map[pos.y][pos.x - 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos.y][pos.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_s_pressed(char *map[], mlx_t *wind)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos.y + 1][pos.x] != '1' && map[pos.y + 1][pos.x] != 'E'
			&& map[pos.y + 1][pos.x] != 'L' && map[pos.y + 1][pos.x] != 'R')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y + 1][pos.x] = 'P';
		ft_moving_patrol(map);
		return (1);
	}
	if (map[pos.y + 1][pos.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos.y][pos.x] = '0';
		return (1);
	}
	return (0);
}
