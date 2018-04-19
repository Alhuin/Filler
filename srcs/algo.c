/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/12 18:29:33 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 14:13:51 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

void				choose_play(t_filler *filler, int piece_i, int piece_j)
{
	float rating;

	rating = ft_sqrt(ft_pow(piece_i - filler->to_rush->y, 2) +
			ft_pow(piece_j - filler->to_rush->x, 2));
	while (filler->one--)
		rating -= 100;
	if (rating < filler->push->rating)
	{
		filler->push->rating = rating;
		filler->push->x = piece_j;
		filler->push->y = piece_i;
		filler->last_play->x = piece_j;
		filler->last_play->y = piece_i;
	}
}

void				test_play(t_filler *filler, int piece_i, int piece_j)
{
	int		i;
	int		j;

	i = -1;
	filler->cross = 0;
	filler->one = 0;
	while (++i < filler->piece->y)
	{
		j = -1;
		while (++j < filler->piece->x)
		{
			if ((filler->piece->save[i][j] == filler->me &&
				filler->map->save[piece_i + i][piece_j + j] == filler->him))
				return ;
			if (filler->piece->save[i][j] == filler->me &&
					filler->map->save[piece_i + i][piece_j + j] == filler->me)
				filler->cross++;
			if (filler->piece->save[i][j] == filler->me &&
					filler->map->save[piece_i + i][piece_j + j] == '1')
				filler->one++;
		}
	}
	if (filler->cross != 1)
		return ;
	choose_play(filler, piece_i, piece_j);
}

int					rush(t_filler *filler)
{
	int		i;
	int		j;
	int		piece_i;
	int		piece_j;

	i = 0;
	while (i < filler->map->y)
	{
		j = 0;
		while (j < filler->map->x)
		{
			piece_i = i - filler->piece->y + 1;
			piece_j = j - filler->piece->x + 1;
			if (piece_i >= 0 && piece_j >= 0)
				test_play(filler, piece_i, piece_j);
			j++;
		}
		i++;
	}
	return (0);
}
