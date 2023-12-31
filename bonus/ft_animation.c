/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:48:50 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 16:51:42 by faveline         ###   ########.fr       */
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

static void	ft_anim_right(t_check pos, mlx_t *wind, mlx_image_t ***img)
{
	char	*anim;

	anim = ft_i_anim("ROR1.png");
	if (ft_redraw_pos(pos, wind, anim, img) < 0)
	{
		ft_error(-7);
		mlx_close_window(wind);
	}
	free(anim);
}

static void	ft_anim_left(t_check pos, mlx_t *wind, mlx_image_t ***img)
{
	char	*anim;

	anim = ft_i_anim("ROL1.png");
	if (ft_redraw_pos(pos, wind, anim, img) < 0)
	{
		ft_error(-7);
		mlx_close_window(wind);
	}
	free(anim);
}

static void	ft_loop_anim2(char *map[], mlx_t *wind, mlx_image_t ***img)
{
	int		i;
	int		j;
	t_check	pos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			pos.x = j;
			pos.y = i;
			if (map[i][j] == 'L')
				ft_anim_left(pos, wind, img);
			if (map[i][j] == 'R')
				ft_anim_right(pos, wind, img);
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
	if (frame++ > 5)
	{
		ft_loop_anim2(window->map_s, window->wind_s, window->img_s);
		frame = 0;
	}
}
