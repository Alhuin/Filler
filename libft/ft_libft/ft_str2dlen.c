/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str2dlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 18:55:17 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/28 18:56:19 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_str2dlen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
