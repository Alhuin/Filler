/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   position.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 15:50:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 13:29:16 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

void			get_first_position(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->map->y)
	{
		j = 0;
		while (j < filler->map->x)
		{
			if (filler->map->save[i][j] == filler->him)
			{
				filler->to_rush->x = j;
				filler->to_rush->y = i;
			}
			j++;
		}
		i++;
	}
}

void			place_one(t_filler *filler, int i, int j)
{
	if (i - 1 >= 0 && filler->map->save[i - 1][j] != filler->him &&
			filler->map->save[i - 1][j] != filler->me)
		filler->map->save[i - 1][j] = '1';
	if (j - 1 >= 0 && filler->map->save[i][j - 1] != filler->him &&
			filler->map->save[i][j - 1] != filler->me)
		filler->map->save[i][j - 1] = '1';
	if (i + 1 < filler->map->y &&
			filler->map->save[i + 1][j] != filler->him &&
			filler->map->save[i + 1][j] != filler->me)
		filler->map->save[i + 1][j] = '1';
	if (j + 1 < filler->map->x &&
			filler->map->save[i][j + 1] != filler->him &&
			filler->map->save[i][j + 1] != filler->me)
		filler->map->save[i][j + 1] = '1';
}

void			best_position(t_filler *filler)
{
	int		i;
	int		j;

	i = -1;
	while (++i < filler->map->y)
	{
		j = -1;
		while (++j < filler->map->x)
		{
			if (filler->map->save[i][j] == filler->him)
				place_one(filler, i, j);
		}
	}
}

void			define_to_rush(t_filler *filler)
{
	int		i;
	int		j;
	float	rating;

	rating = 0;
	i = -1;
	while (++i < filler->map->y)
	{
		j = -1;
		while (++j < filler->map->x)
		{
			if (filler->map->save[i][j] == filler->him)
			{
				rating = ft_sqrt(ft_pow(filler->last_play->y - i, 2)
						+ ft_pow(filler->last_play->x - j, 2));
				if (rating < filler->to_rush->rating)
				{
					filler->to_rush->x = j;
					filler->to_rush->y = i;
					filler->to_rush->rating = rating;
				}
			}
		}
	}
}
