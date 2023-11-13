/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:18 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 11:47:51 by faveline         ###   ########.fr       */
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
	t_check	pos_p;

	pos_p = ft_find_character(map, 'P');
	if (pos_p.x == 0 && pos_p.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos_p.y - 1][pos_p.x] != '1' && map[pos_p.y - 1][pos_p.x] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y - 1][pos_p.x] = 'P';
		return (1);
	}
	if (map[pos_p.y - 1][pos_p.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_d_pressed(char *map[], mlx_t *wind)
{
	t_check	pos_p;

	pos_p = ft_find_character(map, 'P');
	if (pos_p.x == 0 && pos_p.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos_p.y][pos_p.x + 1] != '1' && map[pos_p.y][pos_p.x + 1] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y][pos_p.x + 1] = 'P';
		return (1);
	}
	if (map[pos_p.y][pos_p.x + 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_a_pressed(char *map[], mlx_t *wind)
{
	t_check	pos_p;

	pos_p = ft_find_character(map, 'P');
	if (pos_p.x == 0 && pos_p.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos_p.y][pos_p.x - 1] != '1' && map[pos_p.y][pos_p.x - 1] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y][pos_p.x - 1] = 'P';
		return (1);
	}
	if (map[pos_p.y][pos_p.x - 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_s_pressed(char *map[], mlx_t *wind)
{
	t_check	pos_p;

	pos_p = ft_find_character(map, 'P');
	if (pos_p.x == 0 && pos_p.y == 0)
	{
		mlx_close_window(wind);
		return (3);
	}
	if (map[pos_p.y + 1][pos_p.x] != '1' && map[pos_p.y + 1][pos_p.x] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y + 1][pos_p.x] = 'P';
		return (1);
	}
	if (map[pos_p.y + 1][pos_p.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}
