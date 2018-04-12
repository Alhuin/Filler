/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   position.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 15:50:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/12 20:12:24 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

void			get_position(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->map->y)
	{
		j = 0;
		while (j < filler->map->x)
		{
			if (filler->map->save[i][j] == filler->me ||
					filler->map->save[i][j] == filler->me + 32)
			{
				filler->my_pos->x = j;
				filler->my_pos->y = i;
			}
			if (filler->map->save[i][j] == filler->him ||
					filler->map->save[i][j] == filler->him + 32)
			{
				filler->his_pos->x = j;
				filler->his_pos->y = i;
			}
			j++;
		}
		i++;
	}
}
