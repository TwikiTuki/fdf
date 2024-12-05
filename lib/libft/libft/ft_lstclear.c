
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
