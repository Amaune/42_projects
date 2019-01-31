/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_read_it.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:53:57 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 16:53:58 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		creat_lst(t_lst **tmp, char *buff, int count)
{
	t_lst	*new;
	t_lst	*t;
	char **stmp;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (0);
	stmp = ft_strsplit(buff, '\n');
	new->data = stmp;
	new->next = NULL;
	new->id = count;
	t = *tmp;
	if (*tmp == NULL)
		*tmp = new;
	else
	{
		while (t->next)
			t = t->next;
		t->next = new;
	}
	free(stmp);
	return (1);
}

static void		fill_sl_error(char *buff)
{
	free(buff);
	write(1, "error\n", 1);
	exit(1);
}

t_lst			*fill_read_it(int fd, t_lst *list)
{
	t_lst	*tmp;
	int		n;
	int		count;
	char	*buff;

	n = 1;
	count = 0;
	tmp = list;
	buff = ft_strnew(21);
	while ((n = read(fd, buff, 21)))
	{
		buff[n] = '\0';
		if (!fill_error(buff))
			fill_sl_error(buff);
		if (!creat_lst(&tmp, buff, count))
			return (NULL);
		count++;
	}
	if (ft_strlen(buff) != 20)
		fill_sl_error(buff);
	origin(tmp);
	free(buff);
	return (tmp);
}
