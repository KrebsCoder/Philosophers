/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 02:06:00 by lkrebs-l          #+#    #+#             */
/*   Updated: 2022/07/06 04:19:12 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	create_threads(t_philo *philo);
static void	thread_join(t_philo *philo);
static void	init_linked_list(t_philo *philo);
static void	init_mutex(t_philo *philo);

void	create_philo(t_philo *philo)
{
	init_linked_list(philo);
	init_mutex(philo);
	create_threads(philo);
	thread_join(philo);
	pthread_mutex_destroy(&philo->list->mutex);
	ft_exit(philo->list);
}

static void	thread_join(t_philo *philo)
{
	t_list *tmp;
	int	i;

	i = philo->nbr_forks;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i--;
	}
}

static void	init_mutex(t_philo *philo)
{
	t_list *tmp;
	int		i;

	i = philo->nbr_philos;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_mutex_init(&tmp->mutex, NULL);
		printf("current: %d\n", tmp->id);
		printf("previous: %d\nnext: %d\n", tmp->previous->id, tmp->next->id);
		tmp = tmp->next;
		i--;
	}
}

static void	create_threads(t_philo *philo)
{
	t_list *tmp;
	int		i;

	i = philo->nbr_philos;
	tmp = philo->list;
	while (i > 0)
	{
		pthread_create(&tmp->thread, NULL, &routine, tmp);
		tmp = tmp->next;
		i--;
	}
}

static void	init_linked_list(t_philo *philo)
{
	t_list	*node;
	int		i;

	i = philo->nbr_philos - 1;
	philo->list = ft_lstnew(0, philo);
	while (i > 0)
	{
		node = ft_lstnew(i, philo);
		ft_lstadd_back(philo->list, node);
		i--;
	}
}
