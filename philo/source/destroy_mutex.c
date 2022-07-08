/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:26:09 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 04:21:20 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_mutex(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	tmp = philo->list;
	i = philo->nbr_philos;
	while (i > 0)
	{
		//pthread_mutex_unlock(&tmp->fork);
		pthread_mutex_destroy(&tmp->fork);
		tmp = tmp->next;
		i--;
	}
}
