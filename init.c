/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoo <hugoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:18:39 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/22 15:19:39 by hugoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_rules *rules, char **argv, int argc)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	rules->philo_dead = 0;
	if (argc == 6)
		rules->nb_eat = ft_atoi(argv[5]);
	else
		rules->nb_eat = -1;
	rules->philo = malloc(sizeof(t_philo) * rules->nb_philo);
	if (!rules->philo)
		return ;
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nb_philo);
	if (!rules->forks)
		return ;
}

void	philo_init(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].philo_id = i + 1;
		rules->philo[i].fork_left = &rules->forks[i];
		rules->philo[i].last_diner = ft_time();
		rules->philo[i].rules = rules;
		rules->philo[i].must_eat = rules->nb_eat;
		pthread_mutex_init(&rules->philo[i].lock, NULL);
		i++;
	}
	init_fork(rules);
}

void	init_fork(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (i == 0)
			rules->philo[i].fork_right = &rules->forks[rules->nb_philo - 1];
		else
			rules->philo[i].fork_right = &rules->forks[i - 1];
		i++;
	}
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->print, NULL);
	pthread_mutex_init(&rules->dead, NULL);
	rules->start = ft_time();
}
