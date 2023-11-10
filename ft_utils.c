/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:38:37 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 11:28:05 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char *map[])
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

t_check	ft_find_character(char *map[], char c)
{
	int		i;
	int		j;
	t_check	check;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				check.x = j;
				check.y = i;
				return (check);		
			}
			j++;
		}
		i++;
	}
	return (check.x = 0, check.y = 0, check);
}

int	ft_redraw_pos(int x, int y, mlx_t *wind, char *png)
{
	mlx_texture_t	*text;
	mlx_image_t		*img;

	text = mlx_load_png(png);
	if (!text)
		return (-1);
	img = mlx_texture_to_image(wind, text);
	if (!img)
		return (mlx_delete_texture(text), -1);
	if (mlx_image_to_window(wind, img, x * 32, y * 32) < 0)
		return (mlx_delete_texture(text), -1);
	mlx_delete_texture(text);
	return (1);
}
