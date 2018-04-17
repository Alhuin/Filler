/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   position.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 15:50:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/17 18:45:37 by jjanin-r    ###    #+. /#+    ###.fr     */
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
			if (filler->map->save[i][j] == filler->me)
			{
				filler->my_pos->x = j;
				filler->my_pos->y = i;
				if (i <= filler->map->y / 2 && j <= filler->map->x / 2)
					filler->zone = 1;
				if (i >= filler->map->y / 2 && j >= filler->map->x / 2)
					filler->zone = 4;
			}
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

void			best_position(t_filler *filler)
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
				if (filler->map->save[i - 1][j] != filler->him &&
						filler->map->save[i - 1][j] != filler->me)
					filler->map->save[i - 1][j] = '1';
				if (filler->map->save[i][j - 1] != filler->him &&
						filler->map->save[i][j - 1] != filler->me)
					filler->map->save[i][j - 1] = '1';
				if (filler->map->save[i + 1][j] != filler->him &&
						filler->map->save[i + 1][j] != filler->me)
					filler->map->save[i + 1][j] = '1';
				if (filler->map->save[i][j + 1] != filler->him &&
						filler->map->save[i][j + 1] != filler->me)
					filler->map->save[i][j + 1] = '1';
			}
			if (filler->map->save[i][j] == filler->me)
			{
				if (i >= filler->map->y - 5)
					filler->map->save[filler->map->y - 1][j] = '1';
				if (j >= filler->map->x - 5)
					filler->map->save[i][filler->map->x - 1] = '1';
				if (i <= 5)
					filler->map->save[0][j] = '1';
				if (j <= 5)
					filler->map->save[i][0] = '1';
			}
			j++;
		}
		i++;
	}
}

void			define_to_rush(t_filler *filler)
{
	int		i;
	int		j;
	float	rating;

//	check_blocks(filler);
	rating = 0;
	i = 0;
	while (i < filler->map->y)
	{
		j = 0;
		while (j < filler->map->x)
		{
			if (filler->map->save[i][j] == filler->him || filler->map->save[i][j] == '1')
			{
				rating = sqrt(ft_pow(filler->last_play->y - i, 2) + ft_pow(filler->last_play->x - j, 2));
				if (filler->map->save[i][j] == '1')
					rating = -rating;
				if (rating < filler->to_rush->rating)
					{
						filler->to_rush->x = j;
						filler->to_rush->y = i;
						filler->to_rush->rating = rating;
					}
			}
			j++;
		}
		i++;
	}
}
