/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 16:06:04 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 16:11:02 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lst		*ft_creatlst(const int fd, t_lst **gnlst)
{
	t_lst *tmp;

	tmp = *gnlst;
	while (tmp)
	{
		if (tmp->nb == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	tmp->data = ft_strnew(BUFF_SIZE);
	tmp->nb = fd;
	tmp->next = *gnlst;
	*gnlst = tmp;
	return (tmp);
}

static char			*ft_assimile(const int fd, char *buff, char **str)
{
	char	*tmp;
	int		rd;

	rd = 1;
	while (rd && (!(ft_strchr(*str, '\n'))))
	{
		rd = read(fd, buff, BUFF_SIZE);
		if (rd)
		{
			buff[rd] = '\0';
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buff)))
				return (NULL);
			free(tmp);
		}
	}
	if (!rd && ft_strlen(*str) > 0)
	{
		tmp = *str;
		*str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	free(buff);
	return (*str);
}

static char			*linevalue(char **str)
{
	char	*tmp;
	char	*buff;
	char	*ltmp;

	buff = ft_strchr(*str, '\n');
	tmp = NULL;
	if (buff)
	{
		if (!(ltmp = ft_strsub(*str, 0, buff - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(buff + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(ltmp = ft_strdup(*str)))
		return (NULL);
	if (!(*str) || !tmp)
		ft_strdel(str);
	return (ltmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_lst	*gnlst;
	char			*buff;
	t_lst			*lst;

	if (!(lst = ft_creatlst(fd, &gnlst)))
		return (-1);
	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buff = ft_strnew(BUFF_SIZE + 1))
			|| read(fd, buff, 0) == -1 || (lst->data == NULL
				&& !(lst->data = ft_strnew(0))))
		return (-1);
	if (!(ft_assimile(fd, buff, &lst->data)))
		return (-1);
	if (*lst->data)
	{
		if (!(*line = linevalue(&lst->data)))
			return (-1);
		return (1);
	}
	return (0);
}
