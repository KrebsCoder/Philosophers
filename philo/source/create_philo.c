/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/05 18:46:50 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	create_philo(t_philo *philo)
{
	t_list	*node;
	int		i;

	i = 0;
	while (i < philo->nbr_philos)
	{
		node = ft_lstnew(i);
		ft_lstadd_back(&philo->list, node);
		pthread_create(&node->thread, NULL, &routine, node);
		i++;
	}
	i = 0;
	while (i < philo->nbr_philos)
	{
		pthread_join(node->thread, NULL);
		i++;
	}
	ft_exit(philo->list);
}