/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/27 16:44:52 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/27 16:44:54 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <pthread.h>

# define WIDTH 1280
# define HEIGHT 720
# define THREAD 16
# define SWIDOW WIDTH/ THREAD

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				b;
	int				r;
	int				g;
}					t_color;

typedef struct		s_frac
{
	int				maxit;
	double			cre;
	double			cim;
	double			newre;
	double			newim;
	double			oldre;
	double			oldim;
	double			zoom;
	double			movex;
	double			movey;
}					t_frac;

typedef struct		s_file
{
	int				name;
	int				bpp;
	int				size_l;
	int				endian;
	int				th_i;
	int				th_i_m;
	int				tmp_x;
	int				tmp_y;
	int				radius;
	int				press;
	double			elev;
	double			zoom;
	double			decal_x;
	double			decal_y;
	double			teta;
	double			x_teta;
	double			y_teta;
	double			map_width;
	double			map_height;
	double			z;
	double			z_1;
	double			x_index;
	double			y_index;
	void			*img_ptr;
	char			*img;
	char			*fichier;
	void			*mlx_ptr;
	void			*win_ptr;
	void			(*fct)(struct s_file *file, int x, int y);
	t_color			color;
	t_frac			frac;
}					t_file;

int					event(int key, t_file *file);
void				julia(t_file *file, int x, int y);
void				file_display(t_file *file);
int					mouse_press(int key, int x, int y, t_file *file);
void				multithread(t_file *file);
void				fill_pixel(int x, int y, t_file *file);
void				mandelbrot(t_file *file, int x, int y);
int					mouse_move(int x, int y, t_file *file);
void				burningship(t_file *file, int x, int y);
double				smooth_coloring(t_file *file, int i);
void				set_colors(t_file *file);
int					out(void *param);
void				init2(t_file *file);
void				selector(char *str, t_file *file);

#endif
