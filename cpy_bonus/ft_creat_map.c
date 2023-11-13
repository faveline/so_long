/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:44:30 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 16:26:21 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_malloc_map(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	map = (char **)malloc((i + 1) * sizeof(char *));
	if (map == NULL)
		return (map);
	close(fd);
	return (map);
}

char	**ft_delete_newline(char **map)
{
	int	i;
	int	size;

	i = 0;
	while (map[i])
	{
		size = 0;
		while (map[i][size])
			size++;
		map[i][size - 1] = '\0';
		i++;
	}
	return (map);
}

char	**ft_creat_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	map = ft_malloc_map(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	map[i] = line;
	while (line)
	{
		i++;
		line = get_next_line(fd);
		map[i] = line;
	}
	map = ft_delete_newline(map);
	close(fd);
	return (map);
}
