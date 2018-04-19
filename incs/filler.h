/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 17:43:37 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 13:37:22 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/ft_libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
	float			rating;
}					t_point;

typedef struct		s_map
{
	int				y;
	int				x;
	char			**save;
}					t_map;

typedef struct		s_filler
{
	t_map			*map;
	t_map			*piece;
	t_point			*push;
	t_point			*to_rush;
	t_point			*last_play;
	char			*line;
	int				cross;
	int				one;
	char			me;
	char			him;
}					t_filler;

void				get_map_size(t_filler *filler);
void				get_player(t_filler *filler);
int					get_map(t_filler *filler);
int					get_piece(t_filler *filler);
void				get_first_position(t_filler *filler);
int					rush(t_filler *filler);
void				define_to_rush(t_filler *filler);
void				best_position(t_filler *filler);
int					init_env(t_filler *filler);
void				init_data(t_filler *filler);
int					free_data(t_filler *filler);
void				free_env(t_filler *filler);
#endif
