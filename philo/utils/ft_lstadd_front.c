/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:25:06 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/06 04:22:54 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_lstadd_front(t_list *lst, t_list *new)
{
	if (lst == NULL)
		lst = new;
	else
	{
		new -> next = lst->next;
		new -> previous = lst;
		lst->next->previous = new;
		lst->next = new;
		lst = new;
	}
}
