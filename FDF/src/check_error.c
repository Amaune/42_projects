/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/21 15:45:32 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 15:45:33 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char ***tab)
{
	char	**str;
	int		i;

	i = 0;
	str = *tab;
	while (*str)
	{
		ft_strdel(str);
		i++;
		str = &(*tab)[i];
	}
	ft_memdel((void **)tab);
}

void	free_cord(t_fdf *fdf)
{
	int i;

	i = 0;
	while (i < fdf->map_height)
		free(fdf->f_tab[i++]);
	free(fdf->f_tab);
}

void	free_fdf(t_fdf *fdf, char **tab, char *line)
{
	free_lst(fdf);	
	free(fdf);
	free(line);
	free_tab(&tab);
	write(1, "map error\n", 10);
	exit(0);
}

int		count_line(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

int		check_valid(char **tab, int *count)
{
	if (*count == 0)
		*count = count_line(tab);
	if (count_line(tab) != *count)
		return (0);
	if (count == 0)
		return (0);
	return (1);
}
