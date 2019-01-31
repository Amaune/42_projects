/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 10:05:03 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 10:05:04 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_display(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	fdf->img = mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l, &fdf->endian);
	creat_tab(fdf);
	fdf_algo(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
}

int		mouse_press(int key, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key == 4) 
		fdf->zoom += 2;
	if (key == 5)  
		fdf->zoom -= 2;
	fdf_display(fdf);
	return (0);
}

int		out(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int     deal_key(int key, void *param)
{
	t_fdf *tmp;

	tmp = (t_fdf *)param;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 121)
		tmp->elev -= 0.05;
	if (key == 116)
		tmp->elev += 0.05;
	if (key == 123)
		tmp->decal_x -= 10;
	if (key == 124)
		tmp->decal_x += 10;
	if (key == 125)
		tmp->decal_y += 10;
	if (key == 126)
		tmp->decal_y -= 10;
	if (key == 86)
		tmp->teta -= 0.05;
	if (key == 88)
		tmp->teta += 0.05;
	if (key == 91)
		tmp->x_teta -= 0.05;
	if (key == 84)
		tmp->x_teta += 0.05;
	if (key == 2)
		tmp->y_teta -= 0.05;
	if (key == 0)
		tmp->y_teta += 0.05;
	if (key == 18)
	{
		tmp->color.red = 255;
		tmp->color.green = 0;
		tmp->color.blue = 0;
	}
	if (key == 19)
	{
		tmp->color.red = 0;
		tmp->color.green = 255;
		tmp->color.blue = 0;
	}
	if (key == 20)
	{
		tmp->color.red = 0;
		tmp->color.green = 0;
		tmp->color.blue = 255;
	}
	if (key == 21)
	{
		tmp->color.red = 255;
		tmp->color.green = 255;
		tmp->color.blue = 255;
	}
	if (key == 49)
	{
		tmp->teta = 0;
		tmp->decal_x = WIDTH / 2;
		tmp->decal_y = HEIGHT / 2;
	}
	fdf_display(tmp);
	return (0);
}

int     main(int ac, char **av)
{
	t_fdf	*fdf;;

	if (ac != 2)
		return (0);
	if (!(fdf = malloc(sizeof(t_fdf))))
		return (0);
	fdf->map = NULL;
	fdf->elev = 1;
	fdf->zoom = 30;
	fdf->decal_x = WIDTH / 2;
	fdf->decal_y = HEIGHT / 2;
	fdf->teta = 0;
	fdf->x_teta = 0;
	fdf->y_teta = 0;
	init_color(fdf);
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf");
	fdf_traitement(av[1], fdf);
	fdf_display(fdf);
	mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);
	mlx_hook(fdf->win_ptr, 17, 0, out, (void *)0);
	mlx_hook(fdf->win_ptr, 4, 0, mouse_press, fdf);
	mlx_loop(fdf->mlx_ptr);
}