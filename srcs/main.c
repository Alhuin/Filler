/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 16:00:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 20:03:02 by jjanin-r    ###    #+. /#+    ###.fr     */
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

	filler.line = NULL;
	filler.map = malloc(sizeof(t_map));
	filler.map->save = NULL;
	filler.map->x = 0;
	filler.map->y = 0;
	filler.piece = malloc(sizeof(t_map));
	filler.piece->save = NULL;
	filler.piece->x = 0;
	filler.piece->y = 0;
	filler.push = malloc(sizeof(t_point));
	filler.push->x = 0;
	filler.push->y = 0;
	filler.push->rating = 1000000000000000;
	filler.my_pos = malloc(sizeof(t_point));
	filler.last_play = malloc(sizeof(t_point));
	filler.his_pos = malloc(sizeof(t_map));
	filler.to_rush = malloc(sizeof(t_map));
	filler.u_block = 0;
	filler.d_block = 0;
	filler.r_block = 0;
	filler.l_block = 0;
	filler.zone = 0;
	while (101)
	{
		i = 0;
		j = 0;
		filler.push->x = -1;
		filler.push->y = -1;
		if (start == 1)
			get_player(&filler);
		get_map(&filler);
		get_next_line(0, &filler.line);
		get_piece(&filler);
		filler.to_rush->rating = 1000000000000000;
		if (start == 1)
			get_first_position(&filler);
		else
			define_to_rush(&filler);
		filler.push->rating = 1000000000000000;
		rush(&filler);
		if (filler.push->x == -1 || filler.push->y == -1)
		{
			ft_printf("0 0\n");
			break ;
		}
		ft_printf("%d %d\n", filler.push->y, filler.push->x);
		while (i < filler.map->y)
			ft_strdel(&filler.map->save[i++]);
		free(filler.map->save);
		while (j < filler.piece->y)
			ft_strdel(&filler.piece->save[j++]);
		free(filler.piece->save);
		start = 0;
		//dprintf(2, "*********************************************************YOU PLAYED*******************************************************************************");
		get_next_line(0, &filler.line);
	}
		while (i < filler.map->y)
			ft_strdel(&filler.map->save[i++]);
		free(filler.map->save);
		while (j < filler.piece->y)
			ft_strdel(&filler.piece->save[j++]);
		free(filler.map);
		free(filler.piece);
		free(filler.push);
		free(filler.my_pos);
		free(filler.his_pos);
		free(filler.to_rush);
	return (0);
}
