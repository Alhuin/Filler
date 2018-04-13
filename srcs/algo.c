/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:29:33 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/13 17:20:20 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"
#include <math.h>
int     ft_pow(int x, unsigned int y)
{
	int tmp;
	if (y == 0)
		return (1);
	tmp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
		return (x * tmp * tmp);
}

float   ft_sqrt(float number)
{
	long    i;
	float   x2;
	float   y;
	float   threehalfs;

	threehalfs = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long *)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float *)&i;
	y = y * (threehalfs - (x2 * y * y));
	y = y * (threehalfs - (x2 * y * y));
	return (1 / y);
}

void				test_play(t_filler *filler, int map_i, int map_j)
{
	int i;
	int j;
	int cross;
	int piece_i;
	int piece_j;
	float rating;

	cross = 0;
	i = 0;
	piece_i = map_i - filler->piece->y + 1;
	piece_j = map_j - filler->piece->x + 1;
	if (piece_i < 0 || piece_j < 0)
		return ;
	while (i < filler->piece->y)
	{
		j = 0;
		while (j < filler->piece->x)
		{
			if (map_i + i >= filler->map->y || map_j + j >= filler->map->x)
				return ;
			if ((filler->piece->save[i][j] == filler->me || filler->piece->save[i][j] == filler->me + 32) && (filler->map->save[piece_i + i][piece_j + j] == filler->him ||
						filler->map->save[piece_i + i][piece_j + j] == filler->him + 32))
				return ;
			if (filler->piece->save[i][j] == filler->me && (filler->map->save[piece_i + i][piece_j + j] == filler->me || filler->map->save[piece_i + i][piece_j + j] == filler->me + 32))
				cross++;
			j++;
		}
		i++;
	}
	if (cross != 1)
		return ;
	rating = sqrt(ft_pow(piece_i - filler->his_pos->y, 2) + ft_pow(piece_j - filler->his_pos->x, 2));
//	dprintf(2, "\npiece y = %d, piece x = %d, rating = %f\n", piece_i, piece_j, rating);
	if (rating < filler->push->rating)
	{
		filler->push->rating = rating;
		filler->push->x = piece_j;
		filler->push->y = piece_i;
	}
}

void				best_play(t_filler *filler, int map_i, int map_j)
{
	int i;
	int j;

	i = 0;
	while (i < filler->piece->y)
	{
		j = 0;
		while (j < filler->piece->x)
		{
			test_play(filler, map_i + i, map_j + j);
			j++;
		}
		i++;
	}
}

int					rush(t_filler *filler)
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
					best_play(filler, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
