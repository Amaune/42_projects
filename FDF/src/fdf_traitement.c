/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf_traitement.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/22 11:56:01 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/22 11:56:05 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf1.h"

void	rotate(t_fdf *fdf, t_flst *tmp, int i, int j)
{
	fdf->f_tab[i][j].x = (j - fdf->map_width / 2) * cos(fdf->teta) - (i - fdf->map_height / 2) * sin(fdf->teta);
	fdf->f_tab[i][j].y = (j - fdf->map_width / 2) * sin(fdf->teta) + (i - fdf->map_height / 2) * cos(fdf->teta);
	fdf->f_tab[i][j].z = tmp->i_tab[j] * fdf->elev;
	fdf->f_tab[i][j].y = fdf->f_tab[i][j].y * cos(fdf->x_teta) + tmp->i_tab[j] * fdf->elev * sin(fdf->x_teta);
	fdf->f_tab[i][j].z = tmp->i_tab[j] * fdf->elev * cos(fdf->x_teta) - fdf->f_tab[i][j].y * sin(fdf->x_teta);
	fdf->f_tab[i][j].x = fdf->f_tab[i][j].x * cos(fdf->y_teta) + tmp->i_tab[j] * fdf->elev * sin(fdf->y_teta);
	fdf->f_tab[i][j].z = tmp->i_tab[j] * fdf->elev * cos(fdf->y_teta) - fdf->f_tab[i][j].x * sin(fdf->y_teta);
}


int	creat_tab(t_fdf *fdf)
{
	int		i;
	int		j;
	t_flst	*tmp;

	i = 0;
	tmp = fdf->map;
	if (!(fdf->f_tab = malloc(sizeof(t_pos *) * fdf->map_height)))
		return (0);
    while (i < fdf->map_height)
    {
        if (!(fdf->f_tab[i] = malloc(sizeof(t_pos) * fdf->map_width)))
		    return (0);
        i++;
    }
    i = 0;
	while (i < fdf->map_height)
	{
		j = 0;
		while (j < fdf->map_width)
		{
			rotate(fdf, tmp, i, j);
			j++;
		}
		i++;
		tmp = tmp->next;
	}
	free(tmp);
	return (1);
}

static	int	creat_list(char **c_tab, t_fdf *fdf)
{
	int		i;
	t_flst	*new;
	t_flst	*t;

	if (!(new = (t_flst *)malloc(sizeof(t_flst))))
		return (0);
	if (!(new->i_tab = (int *)malloc(sizeof(int) * fdf->map_width)))
		return (0);
	i = -1;
	while (c_tab[++i])
		new->i_tab[i] = ft_atoi(c_tab[i]);
	new->next = NULL;
	t = fdf->map;
	if (fdf->map == NULL)
		fdf->map = new;
	else
	{
		while (t->next)
			t = t->next;
		t->next = new;
	}
	return (1);
}

int		parsing(char *line, t_fdf *fdf)
{
	char **c_tab;
	int i;

	i = 0;
	c_tab = ft_strsplit(line, ' ');
	while (c_tab[i])
		i++;
	fdf->map_width = i;
	creat_list(c_tab, fdf);
	return (1);
}


int		fdf_traitement(char *src, t_fdf *fdf)
{
	int		h;
	char	*line;
	int		fd;

	h = 0;
	fd = open(src, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		parsing(line, fdf);
		h++;
	}
	fdf->map_height = h;
	creat_tab(fdf);
	return (1);
}