/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:03:06 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/12 15:41:53 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_jeu	*jeu;

	jeu = malloc(sizeof(t_jeu));
	if (jeu == NULL)
		return (ft_putstr_fd("Erreur : erreur d'allocation\n", 2), 1);
	init_pointers(jeu);
	if (final_flash(ac, av) == NULL)
		return (free(jeu), 1);
	jeu->map = get_the_map(jeu, av[1]);
	if (jeu->map == NULL)
		return (ft_putstr_fd("Erreur : process fichier", 2), free(jeu), 1);
	if (check_map(jeu) == false)
		return (ft_free_tab(jeu->map), free(jeu), 1);
	ft_free_tab(jeu->map);
	jeu->map = get_the_map(jeu, av[1]);
	if (jeu->map == NULL)
		return (ft_putstr_fd("Erreur : process fichier", 2), free(jeu), 1);
	jeu->mlx = mlx_init();
	if (jeu->mlx == NULL)
		return (ft_free_tab(jeu->map), free(jeu), ft_putstr_fd("/!MLX\n", 2), 1);
	ignite_game(jeu);
	mlx_hook(jeu->win, 2, 1L << 0, inputs, jeu);
	mlx_hook(jeu->win, 17, 1L << 17, close_game, jeu);
	mlx_loop(jeu->mlx);
	return (0);
}

void	visual_map(char **ap)
{
	int	y;

	y = 0;
	while (ap[y] != NULL)
	{
		ft_printf("%s\n", ap[y]);
		y++;
	}
}

// int	main(int ac, char **av)
// {
// 	t_jeu	*jeu;

// 	(void)ac;
// 	jeu = malloc(sizeof(t_jeu));
// 	if (!jeu)
// 		return (1);
// 	if (final_flash(ac, av) == NULL)
// 		return (free(jeu), 1);
// 	jeu->map = get_the_map(jeu, av[1]);
// 	if (jeu->map == NULL)
// 		return (free(jeu), 1);
// 	if (check_map(jeu) == false)
// 		return (ft_free_tab(jeu->map), free(jeu), 1);
// 	ft_free_tab(jeu->map);
// 	jeu->map = get_the_map(jeu, av[1]);
// 	write (1, "\n", 1);
// 	visual_map(jeu->get.map);
// 	write (1, "\n", 1);
// 	ft_free_tab(jeu->map);
// 	free(jeu);
// 	return (0);
// }
