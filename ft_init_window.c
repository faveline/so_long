/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:55 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 12:01:02 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_draw_wind(mlx_t *wind, char c, mlx_image_t *img, char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				if (mlx_image_to_window(wind, img, j * 32, i * 32) < 0)
					return (-6);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_load_texture(mlx_t *wind, char c, char *png, char *map[])
{
	mlx_texture_t	*text;
	mlx_image_t		*img;

	text = mlx_load_png(png);
	if (!text)
		return (-6);
	img = mlx_texture_to_image(wind, text);
	if (!img)
		return (mlx_delete_texture(text), -6);
	if (ft_draw_wind(wind, c, img, map) < 0)
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

mlx_t	*ft_init_window(char *map[])
{
	mlx_t	*wind;
	t_check	size;

	size = ft_size(map);
	wind = mlx_init(size.x * 32, size.y * 32, "so_long", 1);
	if (ft_load_texture(wind, '0', "background.png", map) < 0)
		return (wind->window = NULL, wind);
	if (ft_load_texture(wind, '1', "obstacle.png", map) < 0)
		return (wind->window = NULL, wind);
	if (ft_load_texture(wind, 'C', "chests.png", map) < 0)
		return (wind->window = NULL, wind);
	if (ft_load_texture(wind, 'P', "charac.png", map) < 0)
		return (wind->window = NULL, wind);
	if (ft_load_texture(wind, 'E', "end.png", map) < 0)
		return (wind->window = NULL, wind);
	return (wind);
}
