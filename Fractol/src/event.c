/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 17:00:54 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 17:00:55 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press(int key, int x, int y, t_file *file)
{
	(void)x;
	(void)y;
	if (key == 4)
		file->frac.zoom += 0.5;
	if (key == 5)
		file->frac.zoom -= 0.5;
	file_display(file);
	return (0);
}

int		mouse_move(int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT)))
		return (0);
	if (x < file->tmp_x)
		file->frac.cRe -= 0.01;
	if (x > file->tmp_x)
		file->frac.cRe += 0.01;
	if (y < file->tmp_y)
		file->frac.cIm -= 0.01;
	if (y > file->tmp_y)
		file->frac.cIm += 0.01;
	file->tmp_x = x;
	file->tmp_y = y;
	file_display(file);
	return (0);
}

int		event(int key, t_file *file)
{
    if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 123)
		file->frac.moveX += 0.01;
	if (key == 124)
		file->frac.moveX -= 0.01;
	if (key == 126)
		file->frac.moveY += 0.01;
	if (key == 	125)
		file->frac.moveY -= 0.01;
	if (key == 69)
		file->frac.cIm += 0.003;
	if (key == 78)
		file->frac.cIm -= 0.003;
	if (key == 116)
		file->frac.cRe += 0.003;
	if (key == 121)
		file->frac.cRe -= 0.003;
	if (key == 24)
		file->frac.maxIterations += 10;
	if (key == 27)
		file->frac.maxIterations -= 10;
	if (key == 18)
		file->radius += 1;
	if (key == 19)
		file->radius -= 1;
	file_display(file);
    return (0);
}