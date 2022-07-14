/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 01:21:48 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 03:04:10 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_list	*ft_lstnew(int id, t_philo *philo)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> philo = philo;
	new -> id = id;
	new -> next = new;
	new -> previous = new;
	new -> eat_counter = 0;
	new -> has_fork = 0;
	return (new);
}
