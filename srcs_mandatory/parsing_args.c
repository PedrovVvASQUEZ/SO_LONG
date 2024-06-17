/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:22:02 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/28 17:21:51 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

const char	*final_flash(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) == 0)
			return (av[1]);
		else
			return (ft_putstr_fd("Erreur : fichier errone\n", 2), NULL);
	}
	else
		return (ft_putstr_fd("Erreur : nombre d'arguments errone\n", 2), NULL);
}

void	init_data_co(t_jeu *v)
{
	v->p = 0;
	v->e = 0;
	v->c = 0;
}

void	init_x_y(t_jeu *v)
{
	v->x = 0;
	v->y = 0;
}
