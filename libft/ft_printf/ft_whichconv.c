/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_whichconv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jjanin-r <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 20:58:44 by jjanin-r     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 21:01:18 by jjanin-r    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_whichconv(int i, char **str, t_param *ptr)
{
	if (i > ptr->conv)
		ptr->conv = i;
	if (i == 1 || i == 6)
		*str += 2;
	else if (i >= 2 && i <= 5)
		*str += 1;
}
