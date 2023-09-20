/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:18:48 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/28 12:02:04 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Wrong Arguments!\n");
			return (0);
		}
		i++;
	}
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
			return (0);
	}
	return (1);
}

int	ft_isdigit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("Wrong Arguments!\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (!max_value(argc, argv))
		return (0);
	return (1);
}

int	max_value(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i++]) > 2147483647)
		{
			printf("Wrong Arguments!\n");
			return (0);
		}
	}
	return (1);
}

long long int	ft_time(void)
{
	struct timeval	t1;
	long long int	timestamp;

	timestamp = 0;
	gettimeofday(&t1, NULL);
	timestamp = (t1.tv_sec * 1000) + (t1.tv_usec / 1000);
	return (timestamp);
}

void	ft_usleep(long int time_ms)
{
	long int	start;

	start = 0;
	start = ft_time();
	while ((ft_time() - start) < time_ms)
		usleep(600);
}
