/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:26:09 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/15 07:01:28 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	pthread_mutex_unlock(&philo->is_printing_mutex);
	pthread_mutex_destroy(&philo->is_printing_mutex);
	pthread_mutex_unlock(&philo->check_deaths);
	pthread_mutex_destroy(&philo->check_deaths);
	tmp = philo->list;
	i = philo->nbr_philos;
	while (i > 0)
	{
		pthread_mutex_unlock(&tmp->fork);
		pthread_mutex_destroy(&tmp->fork);
		tmp = tmp->next;
		i--;
	}
}
