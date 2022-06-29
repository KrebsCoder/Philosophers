/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/29 23:26:59 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


static void	philo_is_eating(t_philo *ph)
{
	printf("tempo_em_ms philo %d está comendo\n", ph->nbr_philos);
}

void *routine(void *philo)
{
	t_philo *ph = philo;
	int	i;


	i = 1;
	while (i)
	{
		philo_is_eating(ph);
		ft_exit(ph);
	}
	return (NULL);
}

void	create_philo(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->nbr_philos)
	{
		pthread_create(&ph->list->thread, NULL, &routine, ph);
		i++;
	}
	i = 0;
	while (i < ph->nbr_philos)
	{
		pthread_join(ph->list->thread, NULL);
		i++;
	}
}