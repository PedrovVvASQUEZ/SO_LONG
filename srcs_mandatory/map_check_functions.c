/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:37:50 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/12 15:19:16 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_characters(t_jeu *v)
{
	v->y = 0;
	while (v->map[v->y] != NULL)
	{
		v->x = 0;
		while (v->map[v->y][v->x] != '\0')
		{
			if ((v->map[v->y][v->x] == '1') || (v->map[v->y][v->x] == '0')
				|| (v->map[v->y][v->x] == 'E') || (v->map[v->y][v->x] == 'C')
					|| (v->map[v->y][v->x] == 'P')
						|| (v->map[v->y][v->x] == 'N'))
				v->x++;
			else
				return (ft_putstr_fd("Err : map infectee\n", 2), false);
		}
		v->y++;
	}
	return (true);
}

bool	check_limits(t_jeu *v)
{
	init_x_y(v);
	while (v->map[v->y] != NULL)
	{
		if ((v->y == (map_height(v) - 1)) || (v->y == 0))
		{
			while (v->map[v->y][v->x] != '\0')
			{
				if (v->map[v->y][v->x] != '1')
					return (ft_putstr_fd("Err : limits\n", 2), false);
				v->x++;
			}
		}
		v->x = 0;
		if ((v->map[v->y][v->x] != '1')
			|| (v->map[v->y][ft_strlen(v->map[v->y]) - 1] != '1'))
			return (ft_putstr_fd("Err : limits\n", 2), false);
		v->y++;
	}
	return (true);
}

bool	check_square(t_jeu *v)
{
	v->y = 0;
	while (v->map[v->y] != NULL)
	{
		if (ft_strlen(v->map[0]) != ft_strlen(v->map[v->y]))
			return (ft_putstr_fd("Err : C pas carre\n", 2), false);
		v->y++;
	}
	return (true);
}

bool	check_content(t_jeu *v)
{
	v->y = 0;
	init_data_co(v);
	while (v->map[v->y] != NULL)
	{
		v->x = 0;
		while (v->map[v->y][v->x] != '\0')
		{
			if (v->map[v->y][v->x] == 'C')
				v->c += 1;
			else if (v->map[v->y][v->x] == 'E')
				v->e += 1;
			else if (v->map[v->y][v->x] == 'P')
			{
				player_pos(v, v->y, v->x);
				v->p += 1;
			}	
			v->x++;
		}
		v->y++;
	}
	if ((v->c >= 1) && (v->e == 1) && (v->p == 1))
		return (true);
	else
		return (ft_putstr_fd("Err : Items manquant ou en double\n", 2), false);
}

bool	check_viability(t_jeu *v)
{
	v->pos.y = v->p_y;
	v->pos.x = v->p_x;
	flood_fill(v, v->pos.y, v->pos.x);
	v->pos.y = 0;
	while (v->map[v->pos.y] != NULL)
	{
		v->pos.x = 0;
		while (v->map[v->pos.y][v->pos.x] != '\0')
		{
			if (v->map[v->pos.y][v->pos.x] != 'C'
				&& v->map[v->pos.y][v->pos.x] != 'E')
				v->pos.x++;
			else
				return (ft_putstr_fd("Err : Items innateignables\n", 2), false);
		}
		v->pos.y++;
	}
	return (true);
}
// bool	check_limits(t_jeu *v) 
// {
// 	init_x_y(v);
// 	while (v->map[v->y] != NULL)
// 	{
// 		if ((v->y == (map_height(v) - 1)) || (v->y == 0))
// 		{
// 			while (v->map[v->y][v->x] != '\0')
// 			{
// 				if (v->map[v->y][v->x] == '1')
// 					v->x++;
// 				if (v->map[v->y][v->x] == '\0')
// 				{
// 					v->y++;
// 					if (v->map[v->y] == NULL)
// 						return (true);
// 				}
// 				else if (v->map[v->y][v->x] != '1')
// 					return (ft_putstr_fd("Err : limits\n", 2), false);
// 			}
// 		}
// 		v->x = 0;
// 		if ((v->map[v->y][v->x] == '1')
// 				&& (v->map[v->y][ft_strlen(v->map[v->y]) - 1] == '1'))
// 			v->y++;
// 		else
// 			return (ft_putstr_fd("Err : limits\n", 2), false);
// 	}
// 	return (true);
// }