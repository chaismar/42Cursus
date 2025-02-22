/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarchai <lmarchai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:19:27 by lmarchai          #+#    #+#             */
/*   Updated: 2023/06/15 13:53:31 by lmarchai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
content: Le contenu du nouvel élément.

Alloue (avec malloc(3)) et renvoie un nouvel
élément. La variable membre ’content’ est
initialisée à l’aide de la valeur du paramètre
’content’. La variable ’next’ est initialisée à
NULL.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->content = content;
	l->next = NULL;
	return (l);
}

/*int main(int ac, char **av)
{
	t_list *elem;
	t_list *next;
	
	int i;
	elem = ft_lstnew("SALUT LES AMIS");
	next = ft_lstnew("SALUT !");
	elem->next = next;
	while (elem)
	{
		elem = elem->next;
	}
}*/