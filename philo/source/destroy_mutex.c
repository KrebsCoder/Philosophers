/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:10:10 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:10:13 by gcosta-d         ###   ########.fr       */
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
