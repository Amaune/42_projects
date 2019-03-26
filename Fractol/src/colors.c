/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/11 18:17:31 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 18:17:33 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	set_colors(t_file *file)
{
	file->color.r = rand();
	file->color.g = rand();
	file->color.b = rand();
}

double	smooth_coloring(t_file *file, int i)
{
	double	sc;
	double	fman;

	fman = (file->frac.newim * file->frac.newim) + (file->frac.newre *
		file->frac.newre);
	sc = i + 1 - log(log(sqrt(fman))) / log(4);
	return (sc);
}
