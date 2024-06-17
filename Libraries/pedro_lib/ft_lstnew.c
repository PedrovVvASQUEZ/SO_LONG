/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgrellie <pgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:55:49 by pgrellie          #+#    #+#             */
/*   Updated: 2024/05/13 18:15:25 by pgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pedro_lib.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nem;

	nem = gc_malloc(&nem, sizeof(t_list));
	if (!nem)
		return (gc_free(&nem, nem), NULL);
	nem->content = content;
	nem->next = NULL;
	return (nem);
}
