/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:35:14 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 12:08:28 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				j;
	unsigned int	i;

	j = ft_lenint(n);
	if (!(res = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	res[j] = '\0';
	if (n < 0)
	{
		i = -n;
		res[0] = '-';
	}
	else
		i = n;
	if (i == 0)
		res[0] = '0';
	while (i)
	{
		res[j - 1] = i % 10 + 48;
		i = i / 10;
		j--;
	}
	return (res);
}
