/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:02:40 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/06/27 19:52:43 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init(t_philo *ph, int argc, char *argv[])
{
	check_arguments(argc, argv);
	ph->nbr_philos = ft_atoi(argv[1]);
	ph->nbr_forks = ph->nbr_philos;
	ph->time_die = ft_atoi(argv[2]);
	ph->time_eat = ft_atoi(argv[3]);
	ph->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		ph->times_must_eat = ft_atoi(argv[5]);
	else
		ph->times_must_eat = 0;
}
