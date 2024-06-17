/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_pics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:06:23 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/13 15:04:12 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	dl_hero(t_jeu *jeu)
{
	char	*filename[HERO_FRAME];

	filename[0] = "Textures/sandro1.xpm";
	filename[1] = "Textures/sandro2.xpm";
	get_anim(jeu, filename, (void **)jeu->hero.anim, HERO_FRAME);
}

static void	dl_bad_guy(t_jeu *jeu)
{
	char	*filename[BG_FRAME];

	filename[0] = "Textures/MV1.xpm";
	filename[1] = "Textures/MV2.xpm";
	get_anim(jeu, filename, (void **)jeu->bad_guy.anim, BG_FRAME);
}

static void	dl_spawn(t_jeu *jeu)
{
	char	*filename[SPAWN_FRAME];

	filename[0] = "Textures/rad1.xpm";
	filename[1] = "Textures/rad2.xpm";
	filename[2] = "Textures/rad3.xpm";
	filename[3] = "Textures/rad4.xpm";
	get_anim(jeu, filename, (void **)jeu->spawn.anim, SPAWN_FRAME);
}

static void	dl_collectible(t_jeu *jeu)
{
	char	*filename[COLLECTIBLE_FRAME];

	filename[0] = "Textures/softc1.xpm";
	filename[1] = "Textures/softc4.xpm";
	filename[2] = "Textures/softc2.xpm";
	filename[3] = "Textures/softc5.xpm";
	filename[4] = "Textures/softc3.xpm";
	filename[5] = "Textures/softc6.xpm";
	get_anim(jeu, filename, (void **)jeu->collectible.anim, COLLECTIBLE_FRAME);
}

void	dl_anim_pics(t_jeu *jeu)
{
	get_image(jeu, "Textures/floor.xpm", &jeu->image.floor);
	get_image(jeu, "Textures/wall.xpm", &jeu->image.wall);
	get_image(jeu, "Textures/exit.xpm", &jeu->image.exit);
	dl_hero(jeu);
	dl_bad_guy(jeu);
	dl_collectible(jeu);
	dl_spawn(jeu);
}
