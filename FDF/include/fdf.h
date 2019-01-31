/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 10:06:19 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 10:06:21 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# include <math.h>
# include <mlx.h>
# include <fcntl.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct		s_flst
{
	int				*i_tab;
	struct s_flst	*next;
}					t_flst;

typedef struct		s_pos
{
	double			x;
	double			y;
	double			z;
	double			z_tmp;
}					t_pos;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
	int				startc;
	int				endc;
	int				color;
}					t_color;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_window;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_brese
{
	double			dx;
	double			dy;
	double			i;
	double			x;
	double			y;
	double			xinc;
	double			yinc;
	double			cumul;
}					t_brese;

typedef struct		s_fdf
{
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
	int				bpp;
	int				size_l;
	int				endian;
	void			*img_ptr;
	char			*img;
	char			*fichier;
	void			*mlx_ptr;
	void			*win_ptr;
	t_color			color;
	t_point			start;
	t_point			end;
	t_flst			*map;
	t_pos			**f_tab;
	
}					t_fdf;

void    			bresenham(t_fdf *fdf);
int					fdf_traitement(char *src, t_fdf *fdf);
void				fdf_algo(t_fdf *fdf);
int					creat_tab(t_fdf *fdf);
void				init_color(t_fdf *fdf);
void				fdf_algo(t_fdf *fdf);
int					get_color(t_brese *bres, t_fdf *fdf);
void				hextorgb(int hex, t_fdf *fdf);

#endif