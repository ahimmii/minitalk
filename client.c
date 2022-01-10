/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:56:58 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/23 17:57:00 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	ms;
	int	r;

	ms = 1;
	r = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			ms = ms * -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = (str[i] - 48) + (r * 10);
		i++;
	}
	return (r * ms);
}

void	signal_done(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Signal Recieved\n", 16);
}

void	give_me_my_binary(char c, int pid)
{
	int		i;
	char	bit;

	i = 8;
	while (i > 0)
	{
		usleep(500);
		bit = c >> --i & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	signal(SIGUSR1, signal_done);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			give_me_my_binary(av[2][i++], pid);
		}
		give_me_my_binary(0, pid);
	}
	else
	{
		write(1, "ERROR", 5);
		exit(1);
	}
	usleep(500);
	return (0);
}
