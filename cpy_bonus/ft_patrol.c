/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patrol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:15:49 by faveline          #+#    #+#             */
/*   Updated: 2023/11/10 17:15:35 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_make_move_right(char *map[], int y, int x, char c)
{
	if (c == 'R' || c == 'D')
	{
		map[y][x + 1] = c;
		map[y][x] = '0';
	}
	else if (c == 'T')
		map[y][x] = 'R';
	else
		map[y][x] = 'L';
}

static void	ft_make_move_left(char *map[], int y, int x, char c)
{
	if (c == 'L' || c == 'D')
	{
		map[y][x - 1] = c;
		map[y][x] = '0';
	}
	else
		map[y][x] = c;
}

static void	ft_patrol_right(char *map[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = size - 1;
		while (j > 0)
		{
			if (map[i][j] == 'R' && map[i][j + 1] == '0')
				ft_make_move_right(map, i, j, 'R');
			else if (map[i][j] == 'R' && map[i][j + 1] == 'P')
				ft_make_move_right(map, i, j, 'D');
			else if (map[i][j] == 'R' && (map[i][j + 1] == '1'
						|| map[i][j + 1] == 'L' || map[i][j + 1] == 'E'
						|| map[i][j + 1] == 'C' || map[i][j + 1] == 'R'
						|| map[i][j + 1] == 'T'))
				ft_make_move_right(map, i, j, 'L');
			else if (map[i][j] == 'T')
				ft_make_move_right(map, i, j, 'T');
			j--;
		}
		i++;
	}
}

static void	ft_patrol_left(char *map[])
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'L' && map[i][j - 1] == '0')
				ft_make_move_left(map, i, j, 'L');
			else if (map[i][j] == 'L' && map[i][j - 1] == 'P')
				ft_make_move_left(map, i, j, 'D');
			else if (map[i][j] == 'L' && (map[i][j - 1] == '1'
						|| map[i][j - 1] == 'R' || map[i][j - 1] == 'E'
						|| map[i][j - 1] == 'C' || map[i][j - 1] == 'L'))
				ft_make_move_left(map, i, j, 'T');
			j++;
		}
		i++;
	}
}

void	ft_moving_patrol(char *map[])
{
	int	size;

	ft_patrol_left(map);
	size = 0;
	while (map[0][size])
		size++;
	ft_patrol_right(map, size);
}
