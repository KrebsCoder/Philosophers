/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/06 04:21:55 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_is_eating(t_list *philo);
static void	philo_is_sleeping(t_list *philo);
static void	philo_is_thinking(t_list *philo);

void	*routine(void *node)
{
	t_list *philo = (t_list *)node;

	gettimeofday(&philo->current_time, NULL);
	printf("%ld\n", philo->current_time.tv_usec * 1000);
	while (1)
	{
		philo_is_eating(philo);
		philo_is_sleeping(philo);
		philo_is_thinking(philo);
	}
	return (NULL);
}

static void	philo_is_eating(t_list *philo)
{
	pthread_mutex_lock(&philo->mutex);
	pthread_mutex_lock(&philo->next->mutex);
	printf("tempo em ms ms filosofo %d está comendo\n", philo->id);
	usleep(philo->philo->time_eat * 1000);
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
}

static void	philo_is_sleeping(t_list *philo)
{
	printf("filosofo %d está dormindo\n", philo->id);
	usleep(philo->philo->time_sleep * 1000);
}

static void	philo_is_thinking(t_list *philo)
{
	printf("filosofo %d está pensando\n", philo->id);
}
