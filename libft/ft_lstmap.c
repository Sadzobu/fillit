#include "libft.h"

static void		ft_lstdelone_f(void *d, size_t n) {
	free(d);
	(void)n;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
    t_list *res;
    t_list *tmpl;
    t_list *tmpr;

    if (!(f && lst))
        return (NULL);
    if (!(res = (t_list *)malloc(sizeof(t_list))))
        return (NULL);
    res = f(lst);
    tmpl = lst;
    tmpr = res;
    while (tmpl->next)
        if (!(tmpr->next =  (t_list *)malloc(sizeof(t_list))))
        {
            ft_lstdel(&res, ft_lstdelone_f);   
            return (NULL);
        }
        else
        {
            tmpr->next = f(tmpl->next);
            tmpr = tmpr->next;
            tmpl = tmpl->next;
        }
    return (res);
}
