/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:44 by faveline          #+#    #+#             */
/*   Updated: 2023/11/07 17:55:53 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_delete(char *map[])
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
		return (NULL);
	}
	return (map);
}

int	main(int argc, char *argv[])
{
	char	**map;
	mlx_t	*wind;

	map = ft_check_arg(argc, argv);
	if (map == NULL)
		return (1);
	wind = ft_init_window(map);
	if (!wind->window)
		return (ft_delete(map), ft_error(-6), 1);
	ft_action_on_hook(wind, map);
	mlx_loop(wind);
	ft_delete(map);
	return (0);
}
