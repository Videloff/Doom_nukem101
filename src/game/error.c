/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: videloff <videloff@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 15:41:02 by yalabidi     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 14:43:21 by videloff    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "doom_nukem.h"

void	usage(void)
{
	ft_putstr("Usage: ./doom-nukem map_name\n");
	ft_putstr("You can create a new map or edit a map with ");
	ft_putstr("those two commands:\n");
	ft_putstr("./doom-nukem create ./doom-nukem edit map_name.\n");
	exit(-1);
}

void	error(int error)
{
	if (error == 1)
	{
		ft_putstr("An error occured while trying to open or read the map.\n");
		ft_putstr("Please check the chmod or the existance of the map\n");
		exit(-1);
	}
	if (error == 2)
	{
		ft_putstr("Syntax error in the map file\n");
		exit(-1);
	}
	if (error == 3)
	{
		ft_putstr("A malloc error occured\n");
		exit(-1);
	}
	if (error == 4)
	{
		ft_putstr("An error occured while the Minilibix initialization\n");
		exit(-1);
	}
}

t_ray	*create_ray(float dist, float mod, float id)
{
	t_ray	*ray;

	if (!(ray = (t_ray*)malloc(sizeof(t_ray))))
		return (NULL);
	ray->dist = dist;
	ray->type = -1;
	ray->ang = -1;
	ray->wall = -1;
	ray->mrg = -1;
	ray->cmpt = -1;
	ray->mod = mod;
	ray->id = id;
	ray->mapy = -1;
	ray->mapx = -1;
	ray->next = NULL ;
	return (ray);
}
