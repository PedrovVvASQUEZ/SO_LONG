/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:49 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/11 18:40:24 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	inputs(int code_touche, t_jeu *jeu)
{
	if (code_touche == UP_arrow || code_touche == W)
		move_up(jeu);
	if (code_touche == LEFT_arrow || code_touche == A)
		move_to_the_left(jeu);
	if (code_touche == DOWN_arrow || code_touche == S)
		move_down(jeu);
	if (code_touche == RIGHT_arrow || code_touche == D)
		move_to_the_right(jeu);
	if (code_touche == ESC)
		close_game(jeu);
	return (0);
}

void	move_up(t_jeu *jeu)
{
	if (jeu->map[jeu->p_y - 1][jeu->p_x] != '1')
	{
		if (jeu->map[jeu->p_y][jeu->p_x] == 'E' && jeu->c == 0)
			exit_game(jeu, 0);
		else if (jeu->map[jeu->p_y - 1][jeu->p_x] == 'E' && jeu->c != 0)
			return ;
		else if (jeu->map[jeu->p_y - 1][jeu->p_x] == 'N')
			exit_game(jeu, 1);
		jeu->map[jeu->p_y][jeu->p_x] = '0';
		jeu->p_y -= 1;
		if (jeu->map[jeu->p_y][jeu->p_x] == 'C')
			jeu->c -= 1;
		jeu->map[jeu->p_y][jeu->p_x] = 'P';
		jeu->steps += 1;
		ft_printf("Steps : %d\n", jeu->steps);
	}
}

void	move_down(t_jeu *jeu)
{
	if (jeu->map[jeu->p_y + 1][jeu->p_x] != '1')
	{
		if (jeu->map[jeu->p_y + 1][jeu->p_x] == 'E' && jeu->c == 0)
			exit_game(jeu, 0);
		else if (jeu->map[jeu->p_y + 1][jeu->p_x] == 'E' && jeu->c != 0)
			return ;
		else if (jeu->map[jeu->p_y + 1][jeu->p_x] == 'N')
			exit_game(jeu, 1);
		jeu->map[jeu->p_y][jeu->p_x] = '0';
		jeu->p_y += 1;
		if (jeu->map[jeu->p_y][jeu->p_x] == 'C')
			jeu->c -= 1;
		jeu->map[jeu->p_y][jeu->p_x] = 'P';
		jeu->steps += 1;
		ft_printf("Steps : %d\n", jeu->steps);
	}
}

void	move_to_the_left(t_jeu *jeu)
{
	if (jeu->map[jeu->p_y][jeu->p_x - 1] != '1')
	{
		if (jeu->map[jeu->p_y][jeu->p_x - 1] == 'E' && jeu->c == 0)
			exit_game(jeu, 0);
		else if (jeu->map[jeu->p_y][jeu->p_x - 1] == 'E' && jeu->c != 0)
			return ;
		else if (jeu->map[jeu->p_y][jeu->p_x - 1] == 'N')
			exit_game(jeu, 1);
		jeu->map[jeu->p_y][jeu->p_x] = '0';
		jeu->p_x -= 1;
		if (jeu->map[jeu->p_y][jeu->p_x] == 'C')
			jeu->c -= 1;
		jeu->map[jeu->p_y][jeu->p_x] = 'P';
		jeu->steps += 1;
		ft_printf("Steps : %d\n", jeu->steps);
	}
}

void	move_to_the_right(t_jeu *jeu)
{
	if (jeu->map[jeu->p_y][jeu->p_x + 1] != '1')
	{
		if (jeu->map[jeu->p_y][jeu->p_x + 1] == 'E' && jeu->c == 0)
			exit_game(jeu, 0);
		else if (jeu->map[jeu->p_y][jeu->p_x + 1] == 'E' && jeu->c != 0)
			return ;
		else if (jeu->map[jeu->p_y][jeu->p_x + 1] == 'N')
			exit_game(jeu, 1);
		jeu->map[jeu->p_y][jeu->p_x] = '0';
		jeu->p_x += 1;
		if (jeu->map[jeu->p_y][jeu->p_x] == 'C')
			jeu->c -= 1;
		jeu->map[jeu->p_y][jeu->p_x] = 'P';
		jeu->steps += 1;
		ft_printf("Steps : %d\n", jeu->steps);
	}
}
