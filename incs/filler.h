/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 17:43:37 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 19:41:19 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/ft_libft/libft.h"
# include <stdio.h>
# define SAME_ZONE 1
# define DIAGONALE 2
# define VERTICALE 3
# define HORIZONTALE 4
# define ENCERCLEMENT 5

typedef struct		s_point
{
	int x;
	int y;
}					t_point;

typedef struct		s_map
{
	int				y;
	int				x;
	char			**save;
	float			rating;
}					t_map;

typedef struct		s_filler
{
	t_map			*map;
	t_map			*piece;
	t_map			*push;
	t_point			*my_pos;
	t_point			*his_pos;
	t_point			*to_rush;
	char			*line;
	int				player;
	char			me;
	char			him;
	int				my_zone;
	int				his_zone;
	int				algo;
}					t_filler;

void			get_map_size(t_filler *filler);
void			get_player(t_filler *filler);
int				get_map(t_filler *filler);
int				get_piece(t_filler *filler);
void			get_position(t_filler *filler);
void			choose_algo(t_filler *filler);
int					rush(t_filler *filler);
#endif
