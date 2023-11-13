/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_on_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:05 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 16:51:07 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_redraw_around(mlx_t *wind, char *map[], t_check pos, mlx_image_t ***img)
{
	if (map[pos.y - 1][pos.x] == '0')
	{
		pos.y = pos.y - 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		pos.y = pos.y + 1;
	}
	if (map[pos.y + 1][pos.x] == '0')
	{
		pos.y = pos.y + 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		pos.y = pos.y - 1;
	}
	if (map[pos.y][pos.x - 1] == '0')
	{
		pos.x = pos.x - 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		pos.x = pos.x + 1;
	}
	if (map[pos.y][pos.x + 1] == '0')
	{
		pos.x = pos.x + 1;
		if (ft_redraw_pos(pos, wind, "background.png", img) == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		pos.x = pos.x - 1;
	}
}

void	ft_redraw(char *map[], mlx_t *wind, int flag, mlx_image_t ***img)
{
	t_check	pos;

	pos = ft_find_character(map, 'P');
	if (pos.x == 0 && pos.y == 0)
	{
		pos = ft_find_character(map, 'E');
		ft_redraw_around(wind, map, pos, img);
	}
	else
	{
		if (flag == 0 && ft_redraw_pos(pos, wind, "charac.png", img) == -1)
		{
			ft_error(-6);
			mlx_close_window(wind);
		}
		ft_redraw_around(wind, map, pos, img);
	}
}

static void	ft_which_key(char key, char *map[], mlx_t *wind, mlx_image_t ***img)
{
	static int	i;

	if (key == 'w' && ft_w_pressed(map, wind) == 1)
		ft_print_screen(wind, i++);
	else if (key == 's' && ft_s_pressed(map, wind) == 1)
		ft_print_screen(wind, i++);
	else if (key == 'a' && ft_a_pressed(map, wind) == 1)
		ft_print_screen(wind, i++);
	else if (key == 'd' && ft_d_pressed(map, wind) == 1)
		ft_print_screen(wind, i++);
	if (ft_redraw_patrol(wind, map, img) < 0)
	{
		ft_error(-6);
		mlx_close_window(wind);
	}
	ft_redraw(map, wind, 1, img);
	ft_redraw(map, wind, 0, img);
}

static void	ft_key_pressed(mlx_key_data_t keydata, void *ptr)
{
	t_wind_map	*window;

	window = (t_wind_map *)ptr;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_which_key('w', window->map_s, window->wind_s, window->img_s);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_which_key('s', window->map_s, window->wind_s, window->img_s);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_which_key('a', window->map_s, window->wind_s, window->img_s);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_which_key('d', window->map_s, window->wind_s, window->img_s);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(window->wind_s);

}

void	ft_action_on_hook(t_wind_map *window)
{
	mlx_key_hook(window->wind_s, &ft_key_pressed, window);
	mlx_loop_hook(window->wind_s, &ft_loop_anim, window);
}
