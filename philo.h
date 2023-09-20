/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:55:10 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/28 10:13:38 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;36m"
# define RED "\033[4;31m"
# define FAILURE	1
# define SUCCESS	0

/**********************************! STRUCTURES !*****************************/

typedef struct s_philo
{
	int					philo_id;
	int					must_eat;
	long long int		last_diner;
	pthread_t			thread;
	pthread_mutex_t		lock;
	pthread_mutex_t		*fork_right;
	pthread_mutex_t		*fork_left;
	struct s_rules		*rules;
}				t_philo;

typedef struct s_rules
{
	int							nb_philo;
	int							time_die;
	int							time_eat;
	int							time_sleep;
	int							nb_eat;
	int							philo_dead;
	long long int				start;
	pthread_t					check_death;
	pthread_mutex_t				print;
	pthread_mutex_t				dead;
	pthread_mutex_t				*forks;
	t_philo						*philo;
}				t_rules;

/**********************************! FONCTIONS !*****************************/

/***********************UTILS*********************************************/

int					ft_check(int argc, char **argv);
int					ft_isdigit(int argc, char **argv);
int					max_value(int argc, char **argv);
void				ft_free(t_rules *rules);
void				ft_usleep(long int time_ms);
unsigned long int	ft_atoi(const char *str);
long long int		ft_time(void);

/***********************INIT*********************************************/

int					philo(t_rules *rules);
void				ft_init(t_rules *rules, char **argv, int argc);
void				philo_init(t_rules *rules);
void				init_fork(t_rules *rules);

/***********************THREAD*********************************************/

int					create_thread(t_rules *rules);
int					ft_join(t_rules *rules);

/***********************ROUTINE*********************************************/

void				routine(t_philo *philo);
void				is_eating(t_philo *philo, pthread_mutex_t *fork_a,
						pthread_mutex_t *fork_b);
void				is_sleeping(t_philo *philo);
void				ft_print(t_philo *philo, char *text, char *color);
void				is_thinking(t_philo *philo);
int					one_philo(t_rules *rules);
int					is_alive(t_philo *philo);
int					check_death(t_rules *rules);

#endif
