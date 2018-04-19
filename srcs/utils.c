/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 12:24:07 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:06:04 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

int					free_data(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strdel(&filler->line);
	while (i < filler->map->y)
		ft_strdel(&filler->map->save[i++]);
	free(filler->map->save);
	while (j < filler->piece->y)
		ft_strdel(&filler->piece->save[j++]);
	free(filler->piece->save);
	return (0);
}

void				free_env(t_filler *filler)
{
	free_data(filler);
	free(filler->map);
	free(filler->piece);
	free(filler->push);
	free(filler->to_rush);
}

int					init_env(t_filler *filler)
{
	filler->line = NULL;
	if (!(filler->map = malloc(sizeof(t_map))))
		return (-1);
	if (!(filler->piece = malloc(sizeof(t_map))))
		return (-1);
	if (!(filler->last_play = malloc(sizeof(t_point))))
		return (-1);
	if (!(filler->to_rush = malloc(sizeof(t_map))))
		return (-1);
	if (!(filler->push = malloc(sizeof(t_point))))
		return (-1);
	filler->map->save = NULL;
	filler->map->x = 0;
	filler->map->y = 0;
	filler->piece->save = NULL;
	filler->piece->x = 0;
	filler->piece->y = 0;
	filler->push->x = 0;
	filler->push->y = 0;
	return (1);
}

void				init_data(t_filler *filler)
{
	filler->push->x = -1;
	filler->push->y = -1;
	filler->piece->x = 0;
	filler->piece->y = 0;
	filler->to_rush->rating = 1000000000000000;
	filler->push->rating = 1000000000000000;
	filler->cross = 0;
	filler->one = 0;
}
