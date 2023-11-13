/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:06:19 by faveline          #+#    #+#             */
/*   Updated: 2023/11/13 13:12:52 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../MLX42/include/MLX42_Int.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"

typedef struct s_check
{
	int		x;
	int		y;
}			t_check;

typedef struct s_wind_map
{
	char		**map_s;
	mlx_t		*wind_s;
}			t_wind_map;


char	**ft_creat_map(char *file);
int		ft_check_map(char *map[]);
t_check	ft_creat_check(char *map[]);
char	**ft_creat_cpy(char *map[], int size, int i, int j);
void	ft_free(char **tab);
void	ft_error(int error);
mlx_t	*ft_init_window(char *map[], int flag);
void	ft_action_on_hook(t_wind_map *window);
int		ft_s_pressed(char *map[], mlx_t *wind);
int		ft_w_pressed(char *map[], mlx_t *wind);
int		ft_a_pressed(char *map[], mlx_t *wind);
int		ft_d_pressed(char *map[], mlx_t *wind);
void	ft_print_map(char *map[]);
t_check	ft_find_character(char *map[], char c);
int		ft_redraw_pos(int x, int y, mlx_t *wind, char *png);
void	ft_print_screen(mlx_t *wind, int i);
int		ft_redraw_pos_anim(int x, int y, mlx_t *wind, char *png);
void	ft_moving_patrol(char *map[]);
int		ft_redraw_patrol(mlx_t *wind, char *map[]);
void	ft_loop_anim(void *ptr);
void	ft_redraw(char *map[], mlx_t *wind, int flag);
void	ft_free_image(mlx_t *wind);

#endif
