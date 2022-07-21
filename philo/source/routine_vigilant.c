/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_vigilant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 01:05:50 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/21 02:09:20 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	check_eat_counter(t_list *philo);

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
			philo->philo->stop_flag = 1;
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
	//int	j;

	tmp = philo;
//	j = philo->philo->nbr_philos * philo->philo
	i = 0;
	while (i < tmp->philo->nbr_philos)
	{
		if (tmp->eat_counter < tmp->philo->times_must_eat)
		{
			//printf("eat counter: %d || philo: %d\n", tmp->eat_counter, tmp->id);
			usleep(1000);
			return (0);
		}
		i++;
		//printf("eat counter: %d || philo: %d || i: %d\n", tmp->eat_counter, tmp->id, i);
		tmp = tmp->next;
	}
	tmp->philo->stop_flag = 1;
	destroy_mutex(philo->philo);
	return (1);
}
