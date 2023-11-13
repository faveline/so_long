/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:44 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 16:55:53 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_delete(void **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	ft_delete_img(void ***img, char *map[])
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(img[i]);
		i++;
	}
	free(img);
}

static char	**ft_check_arg(int argc, char *argv[])
{
	char	**map;
	int		error;

	if (argc != 2)
	{
		ft_printf("ERROR\nWrong arguments.");
		return (NULL);
	}
	map = ft_creat_map(argv[1]);
	if (map == NULL)
	{
		ft_printf("ERROR\nProblem while creating the map.");
		return (NULL);
	}
	error = ft_check_map(map);
	if (error < 0)
	{
		ft_error(error);
		return (ft_delete((void **)map), NULL);
	}
	return (map);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_wind_map	window;

	map = ft_check_arg(argc, argv);
	if (map == NULL)
		return (1);
	window = ft_init_window(map);
	if (!window.wind_s->window || !window.img_s)
		return (ft_delete((void **)map), ft_error(-6), 1);
	ft_action_on_hook(&window);
	mlx_loop(window.wind_s);
	ft_delete_img((void ***)window.img_s, map);
	ft_delete((void **)map);
	mlx_terminate(window.wind_s);
	return (0);
}
