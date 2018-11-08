/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/16 11:04:45 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 17:16:43 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <libc.h>

# define BUFF_SIZE 42

typedef struct		s_lst
{
	int				nb;
	char			*data;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(const int fd, char **line);

#endif
