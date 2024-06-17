/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroyer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:38:42 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/13 18:31:19 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_images(t_jeu *jeu)
{
	if (jeu->image.floor != NULL)
	{
		mlx_destroy_image(jeu->mlx, jeu->image.floor);
		jeu->image.floor = NULL;
	}
	if (jeu->image.wall != NULL)
	{
		mlx_destroy_image(jeu->mlx, jeu->image.wall);
		jeu->image.wall = NULL;
	}
	if (jeu->image.exit != NULL)
	{
		mlx_destroy_image(jeu->mlx, jeu->image.exit);
		jeu->image.exit = NULL;
	}
}

void	destroy_hero(t_jeu *jeu)
{
	int	x;

	x = 0;
	while (x < HERO_FRAME)
	{
		if (jeu->hero.anim[x] != NULL)
		{
			mlx_destroy_image(jeu->mlx, jeu->hero.anim[x]);
			jeu->hero.anim[x] = NULL;
		}
		x++;
	}
}

void	destroy_bad_guy(t_jeu *jeu)
{
	int	x;

	x = 0;
	while (x < BG_FRAME)
	{
		if (jeu->bad_guy.anim[x] != NULL)
		{
			mlx_destroy_image(jeu->mlx, jeu->bad_guy.anim[x]);
			jeu->bad_guy.anim[x] = NULL;
		}
		x++;
	}
}

void	destroy_spawn(t_jeu *jeu)
{
	int	x;

	x = 0;
	while (x < SPAWN_FRAME)
	{
		if (jeu->spawn.anim[x] != NULL)
		{
			mlx_destroy_image(jeu->mlx, jeu->spawn.anim[x]);
			jeu->spawn.anim[x] = NULL;
		}
		x++;
	}
}

void	destroy_collectible(t_jeu *jeu)
{
	int	x;

	x = 0;
	while (x < COLLECTIBLE_FRAME)
	{
		if (jeu->collectible.anim[x] != NULL)
		{
			mlx_destroy_image(jeu->mlx, jeu->collectible.anim[x]);
			jeu->collectible.anim[x] = NULL;
		}
		x++;
	}
}
