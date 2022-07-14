/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrebs-l <lkrebs-l@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:54:36 by gcosta-d          #+#    #+#             */
/*   Updated: 2022/07/14 03:00:51 by lkrebs-l         ###   ########.fr       */
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
	int				has_fork;
	int				eat_counter;
	int				id;
	long			first_fork;
	pthread_t		thread;
	struct s_list	*previous;
	struct s_list	*next;
	struct s_philo	*philo;
	struct timeval	stopped_eating;
	pthread_mutex_t	fork;
}	t_list;

typedef struct s_philo
{
	int				someone_is_dead;
	int				nbr_philos;
	int				nbr_forks;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				times_must_eat;
	int				is_dead;
	int				start_time_flag;
	long			start_time;
	t_list			*list;
	pthread_t		vigilant;
	struct timeval	current_time;
}	t_philo;

void	check_arguments(int argc, char *argv[]);
void	create_philo(t_philo *ph);
void	create_threads(t_philo *philo);
void	thread_join(t_philo *philo);
void	init_linked_list(t_philo *philo);
void	init_mutex(t_philo *philo);
void	destroy_mutex(t_philo *philo);
long	time_in_ms(t_list *philo);
void	start_time(t_philo *philo);
void	detach_thread(t_philo *philo);
void	philo_is_dead(t_philo *philo, int philo_id);

// Routines
void	philo_is_eating(t_list *philo);
void	philo_is_sleeping(t_list *philo);
void	philo_is_thinking(t_list *philo);
void	*routine(void *node);
void	*routine_vigilant(void *node);

// Utils
int		ft_atoi(const char *str);
void	ft_init(t_philo *ph, int argc, char *argv[]);
int		is_str_positive_num(char *str);
void	ft_exit(t_list *list);
t_list	*ft_lstnew(int id, t_philo *philo);
void	ft_lstadd_front(t_list *lst, t_list *new);

#endif