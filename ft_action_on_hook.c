/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_on_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:05 by faveline          #+#    #+#             */
/*   Updated: 2023/11/07 18:48:21 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_check	ft_find_character(char *map[])
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
			if (map[i][j] == 'P')
			{
				check.x = j;
				check.y = i;
				return (check);		
			}
			j++;
		}
		i++;
	}
	return (check);
}

void	ft_w_pressed(void *ptr_map)
{
	char	**map;
	t_check	pos_p;

	map = (char **)&ptr_map;
	pos_p = ft_find_character(map);
	if (pos_p.y - 1 != '1')
	{
		map[pos_p.x][pos_p.y] = '0';
		map[pos_p.x][pos_p.y - 1] = 'P';
	}
}

static void	ft_key_pressed(mlx_key_data_t keydata, void *ptr_map)
{
	static int	i;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		ft_printf("%d\n", i++);
		ft_w_pressed(ptr_map);
	}
}

void	ft_action_on_hook(mlx_t *wind, char	*map[])
{
	mlx_key_hook(wind, &ft_key_pressed, &map);
	//ft_redraw_around(wind, map);
}
