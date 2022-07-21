/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_vigilant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:05:50 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/21 03:47:21 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_eat_counter(t_list *philo);
static void	set_stop_flag(t_philo *philo);

void	*routine_vigilant(void *node)
{
	int		time_last_eaten;
	t_list	*philo;

	philo = (t_list *)node;
	usleep(2100);
	while (!philo->philo->stop_flag)
	{
		pthread_mutex_lock(&philo->philo->is_printing_mutex);
		time_last_eaten = current_time() - philo->stopped_eating;
		if (time_last_eaten > philo->philo->time_die)
		{
			set_stop_flag(philo->philo);
			destroy_mutex(philo->philo);
			break ;
		}
		if (philo->philo->times_must_eat && check_eat_counter(philo))
			return (NULL) ;
		pthread_mutex_unlock(&philo->philo->is_printing_mutex);
		philo = philo->next;
		usleep(500);
	}
	print_philo_is_dead(philo, DIED);
	return (NULL);
}

static int	check_eat_counter(t_list *philo)
{
	t_list	*tmp;
	int	i;

	tmp = philo;
	i = 0;
	while (i < tmp->philo->nbr_philos)
	{
		//pthread_mutex_lock(&tmp->eat_counter_mutex);
		if (tmp->eat_counter < tmp->philo->times_must_eat)
		{
			usleep(500);
			//pthread_mutex_unlock(&tmp->eat_counter_mutex);
			return (0);
		}
		//pthread_mutex_unlock(&tmp->eat_counter_mutex);
		i++;
		tmp = tmp->next;
	}
	tmp->philo->stop_flag = 1;
	destroy_mutex(philo->philo);
	return (1);
}

static void	set_stop_flag(t_philo *philo)
{
	pthread_mutex_lock(&philo->check_deaths);
	philo->stop_flag = 1;
	pthread_mutex_unlock(&philo->check_deaths);
}
