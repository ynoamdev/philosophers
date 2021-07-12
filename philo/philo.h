/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 11:16:48 by ynoam             #+#    #+#             */
/*   Updated: 2021/06/21 11:55:30 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num_of_tm_philo_must_eat;
	int				philo_num;
	long long		*eating;
	long long		*sleeping;
	long long		*start;
	long long		*thinking;
	int				eat;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_t		*threads;
}					t_philo;

t_philo	*g_philo;

int			ft_isdigit(int c);
int			input_error(char *av[]);
int			ft_atoi(const char *str);
void		init_data(char *av[]);
void		init_data2(char *av[]);
long long	gettime(void);
void		takefork(int philo, int fork);
void		eating(int philo, int *j);
void		sleeping(int philo);
void		thinking(int philo);
void		print(int philo);
void		*lunch_ft(void *x);
int			monitor_of_philos(void);
void		create_thread(void);

#endif