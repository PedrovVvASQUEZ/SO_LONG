/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:56:25 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/21 17:04:20 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

t_gc	*g_head(void)
{
	static t_gc	*head = NULL;

	return (head);
}

void	*gc_malloc(size_t size)
{
	void		*ptr;
	t_gc		*node;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	node = malloc(sizeof(t_gc));
	if (!node)
	{
		free(ptr);
		return (NULL);
	}
	node->data = ptr;
	node->next = g_head();
	*(t_gc **)g_head() = node;
	return (ptr);
}

void	gc_free(void *ptr)
{
	t_gc	**node;
	t_gc	*next;

	node = (t_gc **)g_head();
	while (*node)
	{
		if ((*node)->data == ptr)
		{
			next = (*node)->next;
			free((*node)->data);
			free(*node);
			*node = next;
		}
		else
			node = &(*node)->next;
	}
}

void	gc_collect(void)
{
	t_gc	*next;

	while (*(t_gc **)g_head())
	{

		next = g_head()->next;
		free(*(t_gc **)g_head()->data);
		free(*(t_gc **)g_head());
		*(t_gc **)g_head()->data = next;
	}
}
