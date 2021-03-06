/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanne <kanne@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 11:00:59 by jominodi          #+#    #+#             */
/*   Updated: 2020/06/24 11:14:35 by kanne            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "doom_nukem.h"

void	door(t_env *env)
{
	if (env->map[env->door_x][env->door_y].id < 124)
		env->map[env->door_x][env->door_y].id += 1;
	else
	{
		env->map[env->door_x][env->door_y].type = 'F';
		env->door_id = 0;
	}
}

void	jump(t_env *env)
{
	if (env->player.corona == 0)
	{
		if (env->jump_id > 10)
			env->cam.z -= 3;
		else
			env->cam.z += 3;
		env->jump_id++;
		if (env->cam.z == 32)
		{
			env->jump_id = 0;
			env->jump = 0;
		}
	}
}

void	corona(t_env *env)
{
	clock_t	t;

	t = clock();
	if (env->coro_clock == 0 && (env->coro_clock = 1))
		env->t2 = t;
	if (env->t2 + 30000000 > t)
		env->sick = 1;
	else
	{
		env->player.corona = 0;
		env->sick = 0;
		env->coro_clock = 0;
		env->crouch_id = 0;
		env->jump = 0;
		env->jump_id = 0;
		env->cam.z = 32.0000;
		gun(env, 0);
		print_hud(env, 0);
	}
}

void	crouch_animation(t_env *env)
{
	if (env->player.corona == 0)
	{
		if (env->crouch_id != 0)
			env->cam.speed = 3;
		if (env->cam.z > 17 && env->crouch_id == 1)
			env->cam.z -= 3;
		else if (env->cam.z < 32 && env->crouch_id == 2)
			env->cam.z += 3;
		else if (env->cam.z == 32 && env->crouch_id == 2)
		{
			env->cam.speed = 6;
			env->crouch_id = 0;
		}
	}
}

void	display_screen(t_env *env)
{
	clock_t	t_screen;
	int		x;
	int		y;

	t_screen = clock();
	x = 0;
	if (env->clock_screen == 0 && (env->clock_screen = 1))
		env->t5 = t_screen;
	if (env->t5 + 100000 > t_screen)
	{
		while (x++ < 960)
		{
			y = 0;
			while (y++ < 600)
				put_pxl(env, x, y, gclr(0xFF0000, 0));
		}
	}
	else
	{
		env->clock_screen = 0;
		env->player.screen = 0;
	}
}
