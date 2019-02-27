/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_color.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/31 12:13:27 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/31 12:13:28 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	hextorgb(int hex, t_fdf *fdf)
{
	RED = (hex >> 16) & 0xFF;
	GREEN = (hex >> 8) & 0xFF;
	BLUE = (hex) & 0xFF;
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int		get_color(t_brese *bres, t_fdf *fdf)
{
	double	per;

	if (fdf->color.color == ECOLOR)
		return (1);
	if (bres->dx > bres->dy)
		per = percent(fdf->start.x, fdf->end.x, bres->x);
	else
		per = percent(fdf->start.y, fdf->end.y, bres->y);
	if (fabs(fdf->z) < fabs(fdf->z_1))
	{
		RED = get_light((SCOLOR >> 16) & 0xFF, (ECOLOR >> 16) & 0xFF, per);
		GREEN = get_light((SCOLOR >> 8) & 0xFF, (ECOLOR >> 8) & 0xFF, per);
		BLUE = get_light(SCOLOR & 0xFF, ECOLOR & 0xFF, per);
	}
	else
	{
		RED = get_light((ECOLOR >> 16) & 0xFF, (SCOLOR >> 16) & 0xFF, per);
		GREEN = get_light((ECOLOR >> 8) & 0xFF, (SCOLOR >> 8) & 0xFF, per);
		BLUE = get_light(ECOLOR & 0xFF, SCOLOR & 0xFF, per);
	}
	return (1);
}
