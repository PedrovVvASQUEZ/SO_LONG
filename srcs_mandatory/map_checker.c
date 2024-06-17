/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:54:56 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/28 17:21:16 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_map(t_jeu *v)
{
	if (check_characters(v) == true && check_square(v) == true
		&& check_limits(v) == true && check_content(v) == true
		&& check_viability(v) == true)
		return (true);
	else
		return (false);
}
