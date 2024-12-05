
#include "libft.h"
#include "stdio.h"

static void	ft_set_nll(t_list**p1, t_list **p2);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw;
	t_list	*result;
	t_list	*result_last;
	void	*nw_content;

	if (!f)
		return (NULL);
	ft_set_nll(&result, &result_last);
	while (lst)
	{
		nw_content = f(lst->content);
		nw = ft_lstnew(nw_content);
		if (!nw)
		{
			ft_lstclear(&result, del);
			del(nw_content);
			return (NULL);
		}
		ft_lstadd_back(&result_last, nw);
		if (!result)
			result = result_last;
		result_last = nw;
		lst = lst->next;
	}	
	return (result);
}

static void	ft_set_nll(t_list **p1, t_list **p2)
{
	*p1 = NULL;
	*p2 = NULL;
}
