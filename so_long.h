/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:06:19 by faveline          #+#    #+#             */
/*   Updated: 2023/11/09 12:29:24 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"

typedef struct s_check
{
	int		x;
	int		y;
}			t_check;

typedef struct s_wind_map
{
	char	**map_s;
	mlx_t	*wind_s;
}			t_wind_map;

char	**ft_creat_map(char *file);
int		ft_check_map(char *map[]);
t_check	ft_creat_check(char *map[]);
char	**ft_creat_cpy(char *map[], int size, int i, int j);
void	ft_free(char **tab);
void	ft_error(int error);
mlx_t	*ft_init_window(char *map[]);
//void	ft_action_on_hook(mlx_t *wind, char *map[]);
void	ft_action_on_hook(t_wind_map window);
int		ft_s_pressed(void **ptr_map);
int		ft_w_pressed(void **ptr_map);
int		ft_a_pressed(void **ptr_map);
int		ft_d_pressed(void **ptr_map);

#endif
