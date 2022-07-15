/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:23:30 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 04:25:48 by lkrebs-l         ###   ########.fr       */
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
		tmp = tmp->next;
		i--;
	}
	pthread_mutex_init(&philo->is_printing_mutex, NULL);
}
