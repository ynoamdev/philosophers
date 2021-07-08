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

int     ft_isdigit(int c);
int     input_error(char *av[]);
int     ft_atoi(const char *str);
long long	time_sub_from_start(void);

typedef long long (*t_ll_ft)(void);

typedef struct s_philo
{
    t_ll_ft gettime;
    int num_of_tm_philo_must_eat;
    int philo_num;
    long long time_to_die;
    long long time_to_eat;
    long long time_to_sleep;
    long long *eating;
    long long *sleeping;
    long long *start;
    long long *thinking;
    pthread_mutex_t *forks;
    pthread_t *threads;
}   t_philo;

t_philo *g_philo;

#endif