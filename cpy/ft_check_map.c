/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:02:02 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 17:11:18 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_rect(char *map[])
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (map[i][size])
		size++;
	i++;
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j != size)
			return (-2);
		j = 0;
		i++;
	}
	return (size);
}

static int	ft_check_wall(char *map[])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			return (-1);
		j++;
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][j - 1] != '1')
			return (-1);
		i++;
	}
	j = 0;
	while (map[i - 1][j])
	{
		if (map[i - 1][j++] != '1')
			return (-1);
	}
	return (0);
}

static int	ft_check_stendc(char *map[], int start, int end, int nb_c)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C'
					&& map[i][j] != '0' && map[i][j] != '1')
				return (-5);
			if (map[i][j] == 'P')
				start++;
			if (map[i][j] == 'E')
				end++;
			if (map[i][j] == 'C')
				nb_c++;
		}
		j = -1;
	}
	if (start != 1 || end != 1 || nb_c == 0)
		return (-3);
	return (nb_c);
}

static int	ft_check_valid(char *map[], int x, int y, int cpt)
{
	if (map[x][y] == '0' || map[x][y] == 'P')
		map[x][y] = '2';
	if (map[x][y] == 'C' || map[x][y] == 'E')
	{
		map[x][y] = '2';
		cpt++;
	}
	if (map[x - 1][y] != '1' && map[x - 1][y] != '2')
		cpt = ft_check_valid(map, x - 1, y, cpt);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '2')
		cpt = ft_check_valid(map, x, y + 1, cpt);
	if (map[x + 1][y] != '1' && map[x + 1][y] != '2')
		cpt = ft_check_valid(map, x + 1, y, cpt);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '2')
		cpt = ft_check_valid(map, x, y - 1, cpt);
	return (cpt);
}

int	ft_check_map(char *map[])
{
	int		nb_c;
	int		size;
	t_check	check;
	char	**map_cpy;

	size = ft_check_rect(map);
	if (size < 0)
		return (-2);
	if (ft_check_wall(map) < 0)
		return (-1);
	nb_c = ft_check_stendc(map, 0, 0, 0);
	if (nb_c < 0)
		return (nb_c);
	check = ft_creat_check(map);
	map_cpy = ft_creat_cpy(map, size, 0, 0);
	size = ft_check_valid(map_cpy, check.x, check.y, 0);
	if (size != nb_c + 1)
	{
		ft_free(map_cpy);
		return (-4);
	}
	ft_free(map_cpy);
	return (1);
}
