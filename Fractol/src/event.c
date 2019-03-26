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

int		out(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	other(int key, t_file *file)
{
	if (key == 123)
		file->frac.movex += 0.01;
	if (key == 124)
		file->frac.movex -= 0.01;
	if (key == 126)
		file->frac.movey += 0.01;
	if (key == 125)
		file->frac.movey -= 0.01;
	if (key == 69)
		file->frac.cim += 0.003;
	if (key == 78)
		file->frac.cim -= 0.003;
	if (key == 116)
		file->frac.cre += 0.003;
	if (key == 121)
		file->frac.cre -= 0.003;
	if (key == 24)
		file->frac.maxit += 6;
	if (key == 27)
		file->frac.maxit -= 6;
}

int		mouse_press(int key, int x, int y, t_file *file)
{
	if (key == 4)
	{
		file->frac.movex = (x / file->frac.zoom + file->frac.movex) -
		(x / (file->frac.zoom * 1.2));
		file->frac.movey = (y / file->frac.zoom + file->frac.movey) -
		(y / (file->frac.zoom * 1.2));
		file->frac.zoom *= 1.2;
	}
	if (key == 5)
	{
		file->frac.movex = (x / file->frac.zoom + file->frac.movex) -
		(x / (file->frac.zoom / 1.2));
		file->frac.movey = (y / file->frac.zoom + file->frac.movey) -
		(y / (file->frac.zoom / 1.2));
		file->frac.zoom /= 1.2;
	}
	file_display(file);
	return (0);
}

int		mouse_move(int x, int y, t_file *file)
{
	if (!((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT) && file->press != 1))
		return (0);
	if (x < file->tmp_x)
		file->frac.cre -= 0.01;
	if (x > file->tmp_x)
		file->frac.cre += 0.01;
	if (y < file->tmp_y)
		file->frac.cim -= 0.01;
	if (y > file->tmp_y)
		file->frac.cim += 0.01;
	file->tmp_x = x;
	file->tmp_y = y;
	file_display(file);
	return (0);
}

int		event(int key, t_file *file)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 18)
		set_colors(file);
	if (key == 19)
		set_colors(file);
	if (key == 49 && file->press == 0)
		file->press = 1;
	else if (file->press == 1 && key == 49)
		file->press = 0;
	other(key, file);
	file_display(file);
	return (0);
}
