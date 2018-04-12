/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 16:00:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 21:52:41 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

int					main(void)
{
	int			j;
	int			i;
	int			start = 1;
	t_filler	filler;

	i = 0;
	j = 0;
	filler.map = malloc(sizeof(t_map));
	filler.piece = malloc(sizeof(t_map));
	filler.push = malloc(sizeof(t_map));
	filler.push->x = 0;
	filler.push->y = 0;
	filler.push->rating = 1000000000000000;
	filler.my_pos = malloc(sizeof(t_point));
	filler.his_pos = malloc(sizeof(t_map));
	filler.to_rush = malloc(sizeof(t_map));
	while (101)
	{
		if (start == 1)
			get_player(&filler);
		get_map(&filler);
		get_piece(&filler);
		if (start == 1)
			get_position(&filler);
		rush(&filler);
		ft_printf("%i %i\n", filler.push->y, filler.push->x);
		start = 0;
	}
	return (0);
}
