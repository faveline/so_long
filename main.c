/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:58:44 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 17:13:58 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		i;

	map = ft_check_arg(argc, argv);
	if (map == NULL)
		return (1);
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}	
	free(map);
	return (0);
}
