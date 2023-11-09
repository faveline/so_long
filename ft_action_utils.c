/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:22:18 by faveline          #+#    #+#             */
/*   Updated: 2023/11/09 11:32:06 by faveline         ###   ########.fr       */
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
	return (check.x = 0, check.y = 0, check);
}

int	ft_check_if_c(char *map[])
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

int	ft_w_pressed(void **ptr_map)
{
	char	**map;
	t_check	pos_p;

	map = (char **)ptr_map;
	pos_p = ft_find_character(map);
	if (map[pos_p.y - 1][pos_p.x] != '1' && map[pos_p.y - 1][pos_p.x] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y - 1][pos_p.x] = 'P';
		ft_print_map(map);
		return (1);
	}
	if (map[pos_p.y - 1][pos_p.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_d_pressed(void **ptr_map)
{
	char	**map;
	t_check	pos_p;

	map = (char **)ptr_map;
	pos_p = ft_find_character(map);
	if (map[pos_p.y][pos_p.x + 1] != '1' && map[pos_p.y][pos_p.x + 1] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y][pos_p.x + 1] = 'P';
		ft_print_map(map);
		return (1);
	}
	if (map[pos_p.y][pos_p.x + 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_a_pressed(void **ptr_map)
{
	char	**map;
	t_check	pos_p;

	map = (char **)ptr_map;
	pos_p = ft_find_character(map);
	if (map[pos_p.y][pos_p.x - 1] != '1' && map[pos_p.y][pos_p.x - 1] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y][pos_p.x - 1] = 'P';
		ft_print_map(map);
		return (1);
	}
	if (map[pos_p.y][pos_p.x - 1] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}

int	ft_s_pressed(void **ptr_map)
{
	char	**map;
	t_check	pos_p;

	map = (char **)ptr_map;
	pos_p = ft_find_character(map);
	if (map[pos_p.y + 1][pos_p.x] != '1' && map[pos_p.y + 1][pos_p.x] != 'E')
	{
		map[pos_p.y][pos_p.x] = '0';
		map[pos_p.y + 1][pos_p.x] = 'P';
		ft_print_map(map);
		return (1);
	}
	if (map[pos_p.y + 1][pos_p.x] == 'E' && ft_check_if_c(map) == 1)
	{
		map[pos_p.y][pos_p.x] = '0';
		return (1);
	}
	return (0);
}
