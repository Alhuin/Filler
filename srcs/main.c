/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 16:00:24 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:16:55 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

int					parsendo(t_filler *filler, int start)
{
	if (start == 1)
		get_player(filler);
	if (get_map(filler) == 0)
		return (-1);
	get_next_line(0, &filler->line);
	if (get_piece(filler) == 0)
		return (-1);
	best_position(filler);
	if (start == 1)
		get_first_position(filler);
	else
		define_to_rush(filler);
	rush(filler);
	return (0);
}

int					main(void)
{
	int			start;
	t_filler	filler;

	start = init_env(&filler);
	while (101)
	{
		init_data(&filler);
		if (parsendo(&filler, start) == -1)
		{
			free_env(&filler);
			return (-1);
		}
		if (filler.push->x == -1 || filler.push->y == -1)
		{
			ft_printf("0 0\n");
			break ;
		}
		ft_printf("%d %d\n", filler.push->y, filler.push->x);
		start = free_data(&filler);
		get_next_line(0, &filler.line);
		ft_strdel(&filler.line);
	}
	free_env(&filler);
	return (0);
}
