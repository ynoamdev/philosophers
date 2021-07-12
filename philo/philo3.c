/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:17:16 by ynoam             #+#    #+#             */
/*   Updated: 2021/07/12 15:17:18 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takefork(int philo)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%013lld %d has taken a fork\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	eating(int philo)
{
	g_philo->eating[philo] = gettime();
	pthread_mutex_lock(&g_philo->print);
	printf("%013lld %d is eating\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
	usleep(g_philo->time_to_eat - 10000);
}

void	sleeping(int philo, int *j)
{
	g_philo->sleeping[philo] = gettime();
	pthread_mutex_lock(&g_philo->print);
	if (g_philo->num_of_tm_philo_must_eat == *j)
		g_philo->eat = g_philo->eat + 1;
	printf("%013lld %d is sleeping\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	thinking(int philo)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%013lld %d is thinking\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	print(int philo)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%013lld %d died\n", gettime() / 1000, philo + 1);
}
