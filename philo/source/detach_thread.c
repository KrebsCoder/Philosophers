/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 02:48:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/08 03:49:59 by gcosta-d         ###   ########.fr       */
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
		printf("id: %d\n",tmp->id);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
		i--;
	}
}
