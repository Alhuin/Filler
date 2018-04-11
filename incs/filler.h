/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   filler.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 17:43:37 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 20:59:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/ft_libft/libft.h"
# include <stdio.h>

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
	char			*line;
	int				player;
	char			me;
	char			him;
}					t_filler;

#endif
