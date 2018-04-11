/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 17:47:55 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/11 20:56:05 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../incs/filler.h"

static void			get_map_size(t_filler *filler)
{
	int i;

	i = 0;
	while (get_next_line(0, &(filler->line)) > 0)
	{
		if (ft_strstr(filler->line, "Plateau"))
		{
			while (filler->line[i] != ' ')
				i++;
			filler->map->y = ft_atoi(filler->line + i);
			i++;
			while (filler->line[i] != ' ')
				i++;
			filler->map->x = ft_atoi(filler->line + i);
			break ;
		}
	}
	ft_strdel(&filler->line);
}

static void			get_player(t_filler *filler)
{
	get_next_line(0, &(filler->line));
	if (ft_strstr(filler->line, "jjanin-r.filler") &&
			ft_strstr(filler->line, "p1"))
	{
		filler->player = 1;
		filler->me = 'O';
		filler->him = 'X';
	}
	else
	{
		filler->player = 2;
		filler->me = 'X';
		filler->him = 'O';
	}
	ft_strdel(&filler->line);
	get_map_size(filler);
}

static int			get_map(t_filler *filler)
{
	int j;

	j = 0;
	filler->map->save = (char **)malloc(sizeof(char *) * filler->map->y + 1);
	if (filler->map->save == NULL)
		return (0);
	get_next_line(0, &(filler->line));
	ft_strdel(&filler->line);
	while (get_next_line(0, &(filler->line)) > 0 && j < filler->map->y)
		filler->map->save[j++] = ft_strdup(&filler->line[4]);
	filler->map->save[j] = NULL;
	return (1);
}

static int			get_piece(t_filler *filler)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (filler->line[i] != ' ')
		i++;
	filler->piece->y = ft_atoi(filler->line + i);
	i++;
	while (filler->line[i] != ' ')
		i++;
	filler->piece->x = ft_atoi(filler->line + i);
	ft_strdel(&filler->line);
	filler->piece->save = (char **)malloc(sizeof(char *) *
			filler->piece->y + 1);
	if (filler->piece->save == NULL)
		return (0);
	while (get_next_line(0, &(filler->line)) > 0 && j < filler->piece->y)
		filler->piece->save[j++] = ft_strdup(filler->line);
	filler->piece->save[j] = NULL;
	return (1);
}

int					main(void)
{
	int			j;
	int			i;
	t_filler	filler;

	i = 0;
	j = 0;
	filler.map = malloc(sizeof(t_map));
	filler.piece = malloc(sizeof(t_map));
	get_player(&filler);
	get_map(&filler);
	get_piece(&filler);
	dprintf(2, "\nMap saved : \n");
	while (j < filler.map->y)
		dprintf(2, "%s\n", filler.map->save[j++]);
	j = 0;
	dprintf(2, "\nPiece saved : \n");
	while (j < filler.piece->y)
		dprintf(2, "%s\n", filler.piece->save[j++]);
	return (0);
}
