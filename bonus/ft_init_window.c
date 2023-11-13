/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:55 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 16:01:03 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_draw_wind(t_wind_map *window, char c, mlx_texture_t *text)
{
	int			i;
	int			j;
	mlx_image_t	*img;

	i = 0;
	while (window->map_s[i])
	{
		j = 0;
		while (window->map_s[i][j])
		{
			if (window->map_s[i][j] == c)
			{
				img = mlx_texture_to_image(window->wind_s, text);
				if (!img)
					return (-6);
				window->img_s[i][j] = img;
				if (mlx_image_to_window(window->wind_s, img, j * 32, i * 32) < 0)
					return (-6);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_load_texture(t_wind_map *window, char c, char *png)
{
	mlx_texture_t	*text;
	mlx_image_t		*img;

	text = mlx_load_png(png);
	if (!text)
		return (-6);
	img = mlx_texture_to_image(window->wind_s, text);
	if (!img)
		return (mlx_delete_texture(text), -6);
	if (ft_draw_wind(window, c, text) < 0)
		return (mlx_delete_texture(text), -6);
	mlx_delete_texture(text);
	return (1);
}

static t_check	ft_size(char *map[])
{
	t_check	size;
	int		i;
	int		j;

	i = 0;
	while (map[0][i])
		i++;
	size.x = i;
	j = 0;
	while (map[j])
		j++;
	size.y = j;
	return (size);
}


t_wind_map	ft_init_window(char *map[])
{
	mlx_t		*wind;
	t_check		size;
	t_wind_map	window;
	int			i;

	size = ft_size(map);
	wind = mlx_init(size.x * 32, size.y * 32, "so_long", 1);
	window.wind_s = wind;
	window.map_s = map;
	window.img_s = (mlx_image_t ***)malloc((size.y) * sizeof(mlx_image_t **));
	if (window.img_s == NULL)
		return (window);
	i = 0;
	while (i < size.y)
	{
		window.img_s[i] = (mlx_image_t **)malloc((size.x) * sizeof(mlx_image_t *));
		if (window.img_s == NULL)
			return (window);
		i++;
	}
	if (ft_load_texture(&window, '0', "background.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, '1', "obstacle.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, 'C', "chests.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, 'P', "charac.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, 'E', "end.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, 'L', "ROL1.png") < 0)
		return (wind->window = NULL, window);
	if (ft_load_texture(&window, 'R', "ROR1.png") < 0)
		return (wind->window = NULL, window);
	return (window);
}
