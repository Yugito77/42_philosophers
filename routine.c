/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoo <hugoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:15:27 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/22 15:15:55 by hugoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *philo, pthread_mutex_t *fork_a,
pthread_mutex_t *fork_b)
{
	pthread_mutex_lock(fork_a);
	ft_print(philo, "has taken a fork", GREEN);
	pthread_mutex_lock(fork_b);
	ft_print(philo, "has taken a fork", GREEN);
	ft_print(philo, "is eating 🤤", BLUE);
	pthread_mutex_lock(&philo->lock);
	philo->must_eat--;
	philo->last_diner = ft_time();
	pthread_mutex_unlock(&philo->lock);
	ft_usleep(philo->rules->time_eat);
	pthread_mutex_unlock(fork_b);
	pthread_mutex_unlock(fork_a);
}

void	is_sleeping(t_philo *philo)
{
	ft_print(philo, "is sleeping 💤", YELLOW);
	ft_usleep(philo->rules->time_sleep);
}

void	is_thinking(t_philo *philo)
{
	ft_print(philo, "is thinking", PURPLE);
}
