/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:11:43 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/23 02:11:49 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	init_linked_list(t_philo *philo)
{
	t_list	*node;
	int		i;

	i = philo->nbr_philos - 1;
	philo->list = ft_lstnew(0, philo);
	while (i > 0)
	{
		node = ft_lstnew(i, philo);
		ft_lstadd_front(philo->list, node);
		i--;
	}
}
