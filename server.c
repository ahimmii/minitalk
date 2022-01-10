/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:57:18 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/23 17:57:20 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

void	handle(int sig, siginfo_t *sa, void *unused)
{
	static int	i = 0;
	static char	c;
	static int	pid_client = 0;

	unused = 0;
	if (sa->si_pid != pid_client)
	{
		i = 0;
		c = 0;
		pid_client = sa->si_pid;
	}
	c = c << 1 | (sig - 30);
	if (++i == 8)
	{
		if (c == '\0')
		{
			kill(sa->si_pid, SIGUSR1);
			i = 0;
			return ;
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	ds;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	ds.sa_sigaction = &handle;
	sigemptyset(&ds.sa_mask);
	ds.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &ds, NULL);
	sigaction(SIGUSR2, &ds, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
