/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 02:24:18 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/12 02:24:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_threads(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	i = philo->nbr_philos;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		i--;
		usleep(5 * 1000);
	}
}
