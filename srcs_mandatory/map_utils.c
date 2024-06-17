/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:36:47 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/11 18:27:50 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_jeu *v, int y, int x)
{
	if (x >= map_width(v) || y >= map_height(v) || v->map[y][x] == 'X')
		return ;
	if (v->map[y][x] == '1' || v->map[y][x] == 'N')
		return ;
	if (v->map[y][x] == 'E')
	{
		v->map[y][x] = 'X';
		return ;
	}
	v->map[y][x] = 'X';
	flood_fill(v, y + 1, x);
	flood_fill(v, y - 1, x);
	flood_fill(v, y, x + 1);
	flood_fill(v, y, x - 1);
	return ;
}

void	player_pos(t_jeu *v, int y, int x)
{
	v->p_y = y;
	v->p_x = x;
}

void	init_data_get(t_jeu *g)
{
	g->get.fd = 0;
	g->get.line = NULL;
	g->get.fline = NULL;
	g->get.tmp = NULL;
	g->map = NULL;
}

int	map_width(t_jeu *v)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (v->map[y][x] != '\0')
		x++;
	v->map_width = x;
	return (v->map_width);
}

int	map_height(t_jeu *v)
{
	int	y;

	y = 0;
	while (v->map[y] != NULL)
		y++;
	v->map_height = y;
	return (v->map_height);
}
