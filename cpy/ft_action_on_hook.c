/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_on_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:05 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 11:56:45 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_redraw_around(mlx_t *wind, char *map[], t_check pos)
{
	if (map[pos.y - 1][pos.x] == '0' &&
			ft_redraw_pos(pos.x, pos.y - 1, wind, "background.png") == -1)
	{
		ft_error(-6);
		mlx_close_window(wind);
	}
	if (map[pos.y + 1][pos.x] == '0' &&
			ft_redraw_pos(pos.x, pos.y + 1, wind, "background.png") == -1)
	{
		ft_error(-6);
		mlx_close_window(wind);
	}
	if (map[pos.y][pos.x - 1] == '0' &&
			ft_redraw_pos(pos.x - 1, pos.y, wind, "background.png") == -1)
	{
		ft_error(-6);
		mlx_close_window(wind);
	}
	if (map[pos.y][pos.x + 1] == '0' &&
			ft_redraw_pos(pos.x + 1, pos.y, wind, "background.png") == -1)
	{
		ft_error(-6);
		mlx_close_window(wind);
	}
}

static void	ft_redraw(char *map[], mlx_t *wind)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		pos = ft_find_character(map, 'E');
		ft_redraw_around(wind, map, pos);
	}
	else
	{
		if (ft_redraw_pos(pos.x, pos.y, wind, "charac.png") == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		ft_redraw_around(wind, map, pos);
	}
}

static void	ft_which_key(char key, char *map[], mlx_t *wind)
{
	static int	i;

	if (key == 'w' && ft_w_pressed(map, wind) == 1)
	{
		ft_printf("%d\n", i++);
		ft_redraw(map, wind);
	}
	else if (key == 's' && ft_s_pressed(map, wind) == 1)
	{
		ft_printf("%d\n", i++);
		ft_redraw(map, wind);
	}
	else if (key == 'a' && ft_a_pressed(map, wind) == 1)
	{
		ft_printf("%d\n", i++);
		ft_redraw(map, wind);
	}
	else if (key == 'd' && ft_d_pressed(map, wind) == 1)
	{
		ft_printf("%d\n", i++);
		ft_redraw(map, wind);
	}
}

static void	ft_key_pressed(mlx_key_data_t keydata, void *ptr)
{
	t_wind_map	*window;

	window = (t_wind_map *)ptr;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_which_key('w', window->map_s, window->wind_s);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_which_key('s', window->map_s, window->wind_s);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_which_key('a', window->map_s, window->wind_s);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_which_key('d', window->map_s, window->wind_s);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(window->wind_s);
}

void	ft_action_on_hook(t_wind_map *window)
{
	mlx_key_hook(window->wind_s, &ft_key_pressed, window);
}
