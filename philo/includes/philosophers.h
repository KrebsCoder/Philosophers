/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-d <gcosta-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:54:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/07 03:51:46 by gcosta-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_list
{
	pthread_mutex_t	fork;
	pthread_t		thread;
	int				eat_counter;
	int				id;
	struct	s_list	*previous;
	struct	s_list	*next;
	struct	s_philo	*philo;
}	t_list;

typedef struct s_philo
{
	int				nbr_philos;
	int				nbr_forks;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				times_must_eat;
	struct	timeval	start_time;
	struct	timeval	current_time;
	t_list			*list;
}	t_philo;

void	check_arguments(int argc, char *argv[]);
void	create_philo(t_philo *ph);
void	*routine(void *philo);
void	create_threads(t_philo *philo);
void	thread_join(t_philo *philo);
void	init_linked_list(t_philo *philo);
void	init_mutex(t_philo *philo);
long	time_in_ms(t_list *philo);

void	philo_is_eating(t_list *philo);
void	philo_is_sleeping(t_list *philo);
void	philo_is_thinking(t_list *philo);

// Utils
int		ft_atoi(const char *str);
void	ft_init(t_philo *ph, int argc, char *argv[]);
int		is_str_positive_num(char *str);
void	ft_exit(t_list *list);
t_list	*ft_lstnew(int id, t_philo *philo);
void	ft_lstadd_front(t_list *lst, t_list *new);

#endif