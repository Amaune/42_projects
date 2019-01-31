/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:25:14 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 12:00:36 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int find;

	i = 0;
	j = 0;
	while (needle[j])
		j++;
	find = j;
	j = 0;
	if (find == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			if (j == find - 1)
				return ((char *)haystack + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
