/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:32:47 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/07 17:55:01 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	refresh_hero_anim(t_jeu *jeu, int frame_c)
{
	if (frame_c % HERO_DELAY == 0)
	{
		if (jeu->hero.frame == HERO_FRAME - 1)
			jeu->hero.frame = 0;
		else
			jeu->hero.frame++;
	}
}

static void	refresh_collectible_anim(t_jeu *jeu, int frame_c)
{
	if (frame_c % COLLECTIBLE_DELAY == 0)
	{
		if (jeu->collectible.frame == COLLECTIBLE_FRAME - 1)
			jeu->collectible.frame = 0;
		else
			jeu->collectible.frame++;
	}
}

static void	refresh_spawn_anim(t_jeu *jeu, int frame_c)
{
	if (frame_c % SPAWN_DELAY == 0)
	{
		if (jeu->spawn.frame == SPAWN_FRAME - 1)
			jeu->spawn.frame = 0;
		else
			jeu->spawn.frame++;
	}
}

static void	refresh_bad_guy_anim(t_jeu *jeu, int frame_c)
{
	if (frame_c % BG_DELAY == 0)
	{
		if (jeu->bad_guy.frame == BG_FRAME - 1)
			jeu->bad_guy.frame = 0;
		else
			jeu->bad_guy.frame++;
	}
}

int	refresh_anim(t_jeu *jeu)
{
	static int	frame_count = 0;

	frame_count++;
	if (frame_count > 94120)
		frame_count = 0;
	refresh_hero_anim(jeu, frame_count);
	refresh_collectible_anim(jeu, frame_count);
	refresh_spawn_anim(jeu, frame_count);
	refresh_bad_guy_anim(jeu, frame_count);
	if (frame_count % FRAME_DELAY == 0)
	{
		display(jeu);
		display_steps(jeu);
	}
	return (0);
}
