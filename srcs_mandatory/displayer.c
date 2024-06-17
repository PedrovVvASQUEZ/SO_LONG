/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:50:31 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/13 15:00:57 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_image(t_jeu *jeu, char *img_path, void **img_ptr)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	*img_ptr = mlx_xpm_file_to_image(jeu->mlx, img_path, &width, &height);
	if (*img_ptr == NULL)
	{
		ft_printf("Image loading failed : %s\n", img_path);
		close_game(jeu);
	}
}

void	get_anim(t_jeu *jeu, char **filename, void **img_ptr, int frames)
{
	int	height;
	int	width;
	int	x;

	height = 0;
	width = 0;
	x = 0;
	while (x < frames)
	{
		*(img_ptr + x) = mlx_xpm_file_to_image(jeu->mlx, filename[x],
				&width, &height);
		if (*(img_ptr + x) == NULL)
		{
			ft_printf("Animation loading failed : %s\n", filename[x]);
			close_game(jeu);
		}
		x++;
	}
}
		// get_image(jeu, filename[x], &anim[x]);

void	put_image(t_jeu *jeu, char c, int x, int y)
{
	if (c == 'P')
	{
		if (jeu->steps == 0)
			mlx_put_image_to_window(jeu->mlx, jeu->win,
				jeu->spawn.anim[jeu->spawn.frame], x * 64, y * 64);
		else
			mlx_put_image_to_window(jeu->mlx, jeu->win,
				jeu->hero.anim[jeu->hero.frame], x * 64, y * 64);
	}
	else if (c == 'N')
		mlx_put_image_to_window(jeu->mlx, jeu->win,
			jeu->bad_guy.anim[jeu->bad_guy.frame], x * 64, y * 64);
	else if (c == 'C')
		mlx_put_image_to_window(jeu->mlx, jeu->win,
			jeu->collectible.anim[jeu->collectible.frame], x * 64, y * 64);
	else if (c == 'E')
		mlx_put_image_to_window(jeu->mlx, jeu->win,
			jeu->image.exit, x * 64, y * 64);
	else if (c == '1')
		mlx_put_image_to_window(jeu->mlx, jeu->win,
			jeu->image.wall, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(jeu->mlx, jeu->win,
			jeu->image.floor, x * 64, y * 64);
}

void	display(t_jeu *jeu)
{
	int	x;
	int	y;

	y = 0;
	while (jeu->map[y])
	{
		x = 0;
		while (jeu->map[y][x])
		{
			put_image(jeu, jeu->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	display_steps(t_jeu *jeu)
{
	char	*steps;
	char	*message;

	steps = ft_itoa(jeu->steps);
	message = ft_strjoin("/! /! STEPS : ", steps);
	mlx_string_put(jeu->mlx, jeu->win, 10, 50, 0xFFFFFF, message);
	free(steps);
	free(message);
}
