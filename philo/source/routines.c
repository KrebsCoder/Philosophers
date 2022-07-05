/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 02:33:19 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/05 18:45:31 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	philo_is_eating(t_list *ph);
/* static void	philo_is_sleeping(void);
static void	philo_is_thinking(void); */

void	*routine(void *node)
{
	t_list *philo = (t_list *)node;

	while (1)
	{
		philo_is_eating(philo);
		/* philo_is_sleeping();
		philo_is_thinking(); */
	}
	return (NULL);
}

static void	philo_is_eating(t_list *philo)
{
	printf("tempo_em_ms filosofo %d está comendo\n", philo->id);
}

/* static void	philo_is_sleeping(void)
{
	printf("filosofo x está dormindo\n");
}

static void	philo_is_thinking(void)
{
	printf("filosofo x está pensando\n");
} */
