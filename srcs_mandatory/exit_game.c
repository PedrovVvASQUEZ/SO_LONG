/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:28:22 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/11 19:04:21 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_jeu *jeu, int outcome)
{
	if (outcome == 0)
	{
		ft_printf(" !!! You win !!!");
	}
	else if (outcome == 1)
	{
		ft_printf(" ... You lose ...");
	}
	close_game(jeu);
}

	// destroy_images(jeu);
	// destroy_collectible(jeu);
	// destroy_hero(jeu);
	// destroy_bad_guy(jeu);
	// destroy_spawn(jeu);
	// mlx_destroy_window(jeu->mlx, jeu->win);
	// mlx_destroy_display(jeu->mlx);
	// free(jeu->mlx);
	// free(jeu);
	// exit(0);