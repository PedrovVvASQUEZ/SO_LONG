/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:45:17 by pgrellie          #+#    #+#             */
/*   Updated: 2024/06/13 18:38:49 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static bool	check_consecutive_new_lines(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == '\n' && s[x + 1] == '\n')
			return (false);
		x++;
	}
	return (true);
}

char	*read_map(t_jeu *g, char *file_name)
{
	char	*tmp_line;

	init_data_get(g);
	g->get.fd = open(file_name, O_RDONLY);
	if (g->get.fd < 0)
		return (NULL);
	g->get.fline = ft_strdup("");
	if (!g->get.fline)
		return (close(g->get.fd), NULL);
	while (1)
	{
		g->get.tmp = get_next_line(g->get.fd);
		if (g->get.tmp == NULL)
			break ;
		g->get.line = ft_strdup(g->get.tmp);
		tmp_line = ft_strjoin(g->get.fline, g->get.line);
		free(g->get.fline);
		g->get.fline = tmp_line;
		free(g->get.line);
		free(g->get.tmp);
	}
	g->get.tmp = NULL;
	g->get.line = NULL;
	close(g->get.fd);
	return (g->get.fline);
}

char	**get_the_map(t_jeu *g, char *s)
{
	char	*sp;

	sp = read_map(g, s);
	init_data_get(g);
	if (sp == NULL)
		return (ft_putstr_fd("Erreur : Lecture impossible\n", 2), NULL);
	if (check_consecutive_new_lines(sp) == false)
		return (ft_putstr_fd("Erreur : map errone\n", 2), free(sp), NULL);
	g->get.map = ft_split(sp, '\n');
	if (!g->get.map)
		return (ft_free_tab(g->get.map), free(sp), (NULL));
	else
		return (free(sp), g->get.map);
}
