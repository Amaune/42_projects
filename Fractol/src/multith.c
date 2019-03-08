/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multith.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amaune <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/06 15:11:44 by amaune       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/06 15:11:45 by amaune      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void    *frac_algo(void *th_file)
{
    int     x;
    int     y;
    t_file  *file;

    file = (t_file *)th_file;
    y = file->th_i;
    while (y < file->th_i_m)
    {
        x = 0;
        while (x < WIDTH)
        {
            file->fct(file, x, y);
            x++;
        }
        y++;
    }
    return (th_file);
}

void    multithread(t_file *file)
{
    int         i;
    pthread_t   thread[THREAD];
    t_file      th_file[THREAD];

    i = -1;
    while (++i < THREAD)
    {
        th_file[i] = *file;
        th_file[i].th_i = SWIDOW * i;
        th_file[i].th_i_m = SWIDOW * (i + 1);
        pthread_create(&thread[i], NULL, frac_algo, &th_file[i]);
    }
    i = -1;
    while (++i < THREAD)
    {
        pthread_join(thread[i], NULL);
    }
}