/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:16:45 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:16:52 by gcosta-d         ###   ########.fr       */
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
	new -> start_time = 0;
	new -> stopped_eating = 0;
	return (new);
}
