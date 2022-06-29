/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/06/29 02:29:08 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *routine(t_philo *ph){
	int	i;

	i = 1;
	while (i)
	{
		printf("Hello World from Thread! :)\n");
		usleep(1000000);
		printf("Bye World from Thread! :(\n");
		i = 0;
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
		pthread_create(&ph->list->thread, NULL, &routine, (void *)ph);
		i++;
	}
	i = 0;
	while (i < ph->nbr_philos)
	{
		pthread_join(ph->list->thread, NULL);
		i++;
	}
}