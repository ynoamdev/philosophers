#include "philo.h"

void	takefork(int philo, int fork)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%015lld %d has taken a fork\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	eating(int philo, int *j)
{
	int	eatingtime;

	g_philo->eating[philo] = gettime();
	pthread_mutex_lock(&g_philo->print);
	printf("%015lld %d is eating\n", gettime() / 1000, philo + 1);
	if (g_philo->num_of_tm_philo_must_eat == *j)
		g_philo->eat = g_philo->eat + 1;
	pthread_mutex_unlock(&g_philo->print);
}

void	sleeping(int philo)
{
	int	sleepingtime;

	g_philo->sleeping[philo] = gettime();
	pthread_mutex_lock(&g_philo->print);
	printf("%015lld %d is sleeping\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	thinking(int philo)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%015lld %d is thinking\n", gettime() / 1000, philo + 1);
	pthread_mutex_unlock(&g_philo->print);
}

void	print(int philo)
{
	pthread_mutex_lock(&g_philo->print);
	printf("%015lld %d died\n", gettime() / 1000, philo + 1);
}
