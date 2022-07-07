/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:23:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/07 03:24:00 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_mutex(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	i = philo->nbr_philos;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_mutex_init(&tmp->fork, NULL);
		// printf("current: %d\n", tmp->id);
		// printf("previous: %d\nnext: %d\n", tmp->previous->id, tmp->next->id);
		tmp = tmp->next;
		i--;
	}
}
