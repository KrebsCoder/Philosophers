/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:48:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 03:10:33 by lkrebs-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	detach_thread(t_philo *philo)
{
	t_list	*tmp;
	int		i;

	tmp = philo->list;
	i = philo->nbr_philos;
	while (i > 0)
	{
		pthread_detach(tmp->thread);
		tmp = tmp->next;
		i--;
	}
	pthread_detach(philo->vigilant);
}
