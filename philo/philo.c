#include "philo.h"

void	init_data2(char *av[])
{
	int	i;

	i = 0;
	while (i < g_philo->philo_num)
	{
		pthread_mutex_init(&(g_philo->forks[i]), NULL);
		g_philo->start[i] = 0;
		g_philo->eating[i] = 0;
		g_philo->thinking[i] = 0;
		g_philo->sleeping[i++] = 0;
	}
	pthread_mutex_init(&g_philo->print, NULL);
}

void	*lunch_ft(void *x)
{
	int	i;
	int	*j;

	i = *(int *)x;
	j = malloc(sizeof(int));
	*j = 0;
	while (1)
	{
		pthread_mutex_lock(&(g_philo->forks[i]));
		takefork(i, i + 1);
		pthread_mutex_lock(&(g_philo->forks[(i + 1) % g_philo->philo_num]));
		takefork(i, (i + 1) % g_philo->philo_num + 1);
		*j = *j + 1;
		eating(i, j);
		while (gettime() - g_philo->eating[i] <= g_philo->time_to_eat)
			;
		pthread_mutex_unlock(&(g_philo->forks[i]));
		pthread_mutex_unlock(&(g_philo->forks[(i + 1) % g_philo->philo_num]));
		sleeping(i);
		while (gettime() - g_philo->sleeping[i] <= g_philo->time_to_sleep)
			;
		thinking(i);
	}
	return (NULL);
}

int	monitor_of_philos(void)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < g_philo->philo_num)
		{
			if (gettime() - g_philo->eating[i] >= g_philo->time_to_die)
			{
				print(i);
				return (1);
			}
			i++;
		}
		if (g_philo->eat)
			if (g_philo->eat == g_philo->philo_num)
				return (1);
	}
	return (1);
}

void	create_thread(void)
{
	int	i;
	int	*x;

	i = 0;
	while (i < g_philo->philo_num)
	{
		x = malloc(sizeof(int));
		*x = i;
		g_philo->eating[i] = gettime();
		pthread_create(&(g_philo->threads[i]), NULL, &lunch_ft, x);
		usleep(100);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	if (ac == 6 || ac == 5)
	{
		if (input_error(av))
			return (1);
		init_data(av);
		create_thread();
		return (monitor_of_philos());
	}
	else
		printf("error\n");
	return (1);
}
