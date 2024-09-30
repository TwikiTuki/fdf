/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrenau-v <jrenau-v@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:48:01 by jrenau-v          #+#    #+#             */
/*   Updated: 2022/10/04 17:47:04 by jrenau-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*to_delete;
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		to_delete = current;
		current = current -> next;
		ft_lstdelone(to_delete, del);
	}
	*lst = NULL;
}
