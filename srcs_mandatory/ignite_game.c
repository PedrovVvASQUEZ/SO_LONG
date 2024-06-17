/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ignite_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:08:14 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/12 15:53:13 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_anim_pointers(void **anim, int frames)
{
	int	i;

	i = 0;
	while (i < frames)
	{
		anim[i] = NULL;
		i++;
	}
}

void	init_pointers(t_jeu *jeu)
{
	jeu->c = 0;
	jeu->e = 0;
	jeu->p = 0;
	jeu->image.floor = NULL;
	jeu->image.wall = NULL;
	jeu->image.exit = NULL;
	jeu->mlx = NULL;
	jeu->win = NULL;
	init_anim_pointers((void **)jeu->hero.anim, HERO_FRAME);
	init_anim_pointers((void **)jeu->bad_guy.anim, BG_FRAME);
	init_anim_pointers((void **)jeu->collectible.anim, COLLECTIBLE_FRAME);
	init_anim_pointers((void **)jeu->spawn.anim, SPAWN_FRAME);
}

void	ignite_game(t_jeu *jeu)
{
	mlx_get_screen_size(jeu->mlx, &jeu->screen_width, &jeu->screen_height);
	if (jeu->map_width * 64 > jeu->screen_width
		|| jeu->map_height * 64 > jeu->screen_height)
	{
		ft_putstr_fd("Erreur : map trop grande\n", 2);
		mlx_destroy_display(jeu->mlx);
		ft_free_tab(jeu->map);
		free(jeu->mlx);
		free(jeu);
		exit(0);
	}
	jeu->win = mlx_new_window(jeu->mlx, jeu->map_width * 64,
			jeu->map_height * 64, "Sandro's adventures");
	jeu->hero.frame = 0;
	jeu->collectible.frame = 0;
	jeu->spawn.frame = 0;
	jeu->bad_guy.frame = 0;
	jeu->steps = 0;
	dl_anim_pics(jeu);
	display(jeu);
	mlx_loop_hook(jeu->mlx, refresh_anim, jeu);
}
