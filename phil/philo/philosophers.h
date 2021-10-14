/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sscarecr <sscarecr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:05:40 by sscarecr          #+#    #+#             */
/*   Updated: 2021/10/14 23:58:40 by sscarecr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define TRUE	1
# define FALSE	0
# define STEP	5

typedef struct s_philo
{
	int				num;
	int				meals;
	long long		last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	void			*game;
}	t_philo;

typedef struct s_game
{
	long long		ttd;
	long long		tte;
	long long		tts;
	int				number;
	int				max_meals;
	int				finished;
	int				stop;
	pthread_mutex_t	output;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t		*threads;
}	t_game;

int			get_nonnegative(char *s);
int			usage(void);
int			error(void);
long long	now(void);
int			clear(t_game *game);

#endif