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
# define STEP	100
# define SEM	"/forks"
# define OUT	"/output"
# define ACC	"/access"
# define DEA	"/death"
# define FED	"/fed"

# include <sys/types.h>

typedef struct s_game
{
	long long		ttd;
	long long		tte;
	long long		tts;
	long long		last_meal;
	int				number;
	int				max_meals;
	int				finished;
	int			id;
	sem_t	*forks;
	sem_t	*output;
	sem_t	*access;
	sem_t	*death;
	sem_t	*fed;
}	t_game;

int			get_nonnegative(char *s);
int			usage(void);
int			error(void);
long long	now(void);
int			clear(t_game *game);

#endif