/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_error.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 11:28:06 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 11:28:08 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../include/fillit.h"

static int		testpoint(char *buff)
{
	int	i;
	int nbp;
	int nbd;

	i = 0;
	nbp = 0;
	nbd = 0;
	while (buff[i])
	{
		if ((buff[i] != '.') && (buff[i] != '#') && (buff[i] != '\n'))
			return (0);
		if (buff[i] == '.')
			nbp++;
		if (buff[i] == '#')
			nbd++;
		i++;
	}
	if ((nbp != 12) || (nbd != 4))
		return (0);
	return (1);
}

static int		testdieze(char *buff)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
		{
			if (i > 5)
				if (buff[i - 5] == '#')
					count++;
			if (i < 16)
				if (buff[i + 5] == '#')
					count++;
			if (i > 1)
				if (buff[i - 1] == '#')
					count++;
			if (i < 20)
				if (buff[i + 1] == '#')
					count++;
		}
		i++;
	}
	return (count >= 4 ? 1 : 0);
}

static int		testligne(char *buff)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	if (count != 4)
		return (0);
	return (1);
}

int				fill_error(char *buff)
{
	static int i = 0;

	i++;
	if (testpoint(buff) == 0)
		return (0);
	if (testdieze(buff) == 0)
		return (0);
	if (testligne(buff) == 0)
		return (0);
	if (i > 26)
		return (0);
	return (1);
}
