/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/30 11:38:46 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/30 11:38:47 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	init_color(t_fdf *fdf)
{
	fdf->color.red = 0;
	fdf->color.green = 0;
	fdf->color.blue = 0;
	fdf->color.startc = 0xFFFFFF;
	fdf->color.endc = 0xFF5500;
}