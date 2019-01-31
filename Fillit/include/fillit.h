/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/04 14:20:32 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/04 14:20:38 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/include/libft.h"
# include <fcntl.h>
# include <string.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_lst
{
	char			**data;
	struct s_lst	*next;
	t_point			coord[4];
	int				id;
}					t_lst;

typedef struct		s_map
{
	int				size;
	char			**tab;
}					t_map;

t_lst				*fill_read_it(int fd, t_lst *list);
int					fill_error(char *buff);
t_map				*map_creator(int size, t_map *map);
void				map_display(t_map *map);
t_map				*fill_solve(t_lst *list, t_map *map);
int					lstcount(t_lst *list);
int					fill_alg(t_lst *list, t_map *map);
void				origin(t_lst *list);
void				list_free(t_lst *list);
void				map_free(t_map *map);

#endif
