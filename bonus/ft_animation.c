/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:48:50 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 11:58:51 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_i_anim(char *png)
{
	static int	i;
	int			j;
	char		*cpy;

	j = 0;
	cpy = (char *)malloc(9 * sizeof(char));
	while (png[j])
	{
		cpy[j] = png[j];
		j++;
	}
	i = i % 6;
	cpy[3] = i + 48;
	i++;
	cpy[8] = '\0';
	return (cpy);
}

static void	ft_anim_right(int j, int i, mlx_t *wind)
{
	char	*anim;

	anim = ft_i_anim("ROR1.png");
	if (ft_redraw_pos(j, i, wind, anim) < 0)
	{
		ft_error(-7);
		mlx_close_window(wind);
	}
	free(anim);
}

static void	ft_anim_left(int j, int i, mlx_t *wind)
{
	char	*anim;

	anim = ft_i_anim("ROL1.png");
	if (ft_redraw_pos(j, i, wind, anim) < 0)
	{
		ft_error(-7);
		mlx_close_window(wind);
	}
	free(anim);
}

static void	ft_loop_anim2(char *map[], mlx_t *wind)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'L')
				ft_anim_left(j, i, wind);
			if (map[i][j] == 'R')
				ft_anim_right(j, i, wind);
			j++;
		}
		i++;
	}
}

void	ft_loop_anim(void *ptr)
{
	static int	frame;
	t_wind_map	*window;

	window = (t_wind_map *)ptr;
	if (frame++ > 30)
	{
		ft_loop_anim2(window->map_s, window->wind_s);
		frame = 0;
		ft_redraw(window->map_s, window->wind_s, 0);
	}
}
