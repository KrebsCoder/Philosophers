/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:02:40 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 04:23:38 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init(t_philo *philo, int argc, char *argv[])
{
	check_arguments(argc, argv);
	philo->nbr_philos = ft_atoi(argv[1]);
	philo->nbr_forks = philo->nbr_philos;
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->is_dead = -1;
	philo->start_time_flag = 0;
	if (argv[5])
		philo->times_must_eat = ft_atoi(argv[5]);
	else
		philo->times_must_eat = 0;
}
