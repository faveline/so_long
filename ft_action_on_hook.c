/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_on_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:56:05 by faveline          #+#    #+#             */
/*   Updated: 2023/11/09 13:05:23 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_key_pressed_map(mlx_key_data_t keydata, void *ptr)
{
	static int	i;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		if (ft_w_pressed(ptr) == 1)
			ft_printf("%d\n", i++);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{

		if (ft_s_pressed(ptr) == 1)
			ft_printf("%d\n", i++);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		if (ft_a_pressed(ptr) == 1)
			ft_printf("%d\n", i++);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{

		if(ft_d_pressed(ptr) == 1)
			ft_printf("%d\n", i++);
	}
}



void	ft_action_on_hook(t_wind_map window)
{	// window -> pointeru ???
	mlx_key_hook(window.wind_s, &ft_key_pressed_map, window.map_s);
}
