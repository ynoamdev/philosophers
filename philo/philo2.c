#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	input_error(char *av[])
{
	int	i;
	int	j;
	int	error;

	i = 1;
	error = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			if (!ft_isdigit(av[i][j++]))
				error++;
		i++;
	}
	if (ft_atoi(av[1]) <= 1 || error)
	{
		printf("error\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;
	int	test;

	i = 0;
	number = 0;
	sign = 1;
	test = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= 48 && str[i] <= 57 && ++test)
		number = (number * 10) + str[i++] - 48;
	if (test > 10 && sign == 1)
		return (-1);
	if (test > 10 && sign == -1)
		return (0);
	return (number * sign);
}

void	init_data(char *av[])
{
	int	i;

	g_philo = malloc(sizeof(t_philo));
	g_philo->philo_num = ft_atoi(av[1]);
	g_philo->forks = malloc(sizeof(pthread_mutex_t) * g_philo->philo_num);
	g_philo->threads = malloc(sizeof(pthread_t) * g_philo->philo_num);
	g_philo->eating = malloc(sizeof(long long) * g_philo->philo_num);
	g_philo->sleeping = malloc(sizeof(long long) * g_philo->philo_num);
	g_philo->thinking = malloc(sizeof(long long) * g_philo->philo_num);
	g_philo->start = malloc(sizeof(long long) * g_philo->philo_num);
	g_philo->time_to_die = ft_atoi(av[2]) * 1000;
	g_philo->time_to_eat = ft_atoi(av[3]) * 1000;
	g_philo->time_to_sleep = ft_atoi(av[4]) * 1000;
	g_philo->num_of_tm_philo_must_eat = 0;
	g_philo->eat = 0;
	if (av[5])
		g_philo->num_of_tm_philo_must_eat = ft_atoi(av[5]);
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

long long	gettime(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_usec + (now.tv_sec * 1000000));
}
