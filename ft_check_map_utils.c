/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:55:17 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 17:05:39 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_check	ft_creat_check(char *map[])
{
	int		i;
	int		j;
	t_check	check;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				check.x = i;
				check.y = j;
				return (check);
			}
			j++;
		}
		i++;
	}
	return (check);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_creat_cpy(char *map[], int size, int i, int j)
{
	char	**cpy;

	while (map[i])
		i++;
	cpy = (char **)malloc((i + 1) * sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	i = -1;
	while (map[++i])
	{
		j = -1;
		cpy[i] = (char *)malloc((size + 1) * sizeof(char));
		if (cpy[i] == NULL)
		{
			ft_free(cpy);
			return (NULL);
		}
		while (map[i][++j])
			cpy[i][j] = map[i][j];
		cpy[i][j] = '\0';
	}
	cpy[i] = NULL;
	return (cpy);
}
