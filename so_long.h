/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:06:19 by faveline          #+#    #+#             */
/*   Updated: 2023/11/06 17:11:46 by faveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

char	**ft_creat_map(char *file);
int		ft_check_map(char *map[]);
t_check	ft_creat_check(char *map[]);
char	**ft_creat_cpy(char *map[], int size, int i, int j);
void	ft_free(char **tab);
void	ft_error(int error);

#endif
