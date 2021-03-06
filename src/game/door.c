/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videloff <videloff@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:32:59 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/22 14:29:22 by videloff         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

t_ray	*add_doors_v(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[1] + xy[3] / 2) % 64, 9);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	door->mapy = (int)xy[1] / 64;
	return (door);
}

t_ray	*add_doors_v2(float xy[4], t_env *env, float ang)
{
	t_ray	*door;

	door = create_ray(sqrt(pow(env->cam.y -
		(int)(xy[0] + xy[2] / 2), 2) + pow(env->cam.x -
		(int)(xy[1] + xy[3] / 2), 2)) * cos((ang - env->cam.angle)
		* RAD), (int)(xy[1] + xy[3] / 2) % 64, 13);
	door->door = (int)env->map[(int)xy[1] / 64][(int)xy[0] /
		64].id - 60;
	door->type = 3;
	door->mapx = (int)xy[0] / 64;
	return (door);
}

void	setup_door_h(t_env *env, float xy[4], float ang, t_ray **spr)
{
	if (check_key(env->player.key, env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id) == 0 || !ft_isdigit(env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id))
	{
		(*spr)->next = add_doors_h2(xy, env, ang);
		*spr = (*spr)->next;
	}
	(*spr)->next = add_doors_h(xy, env, ang);
}

void	setup_door_v(t_env *env, float xy[4], float ang, t_ray **spr)
{
	if (check_key(env->player.key, env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id) == 0 || !ft_isdigit(env->map[(int)xy[1] / 64]
		[(int)xy[0] / 64].id))
	{
		(*spr)->next = add_doors_v2(xy, env, ang);
		*spr = (*spr)->next;
	}
	(*spr)->next = add_doors_v(xy, env, ang);
}
