/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahimmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:56:40 by ahimmi            #+#    #+#             */
/*   Updated: 2021/12/23 17:56:43 by ahimmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <libc.h>

void	signal_done(int sig);
void	give_me_my_binary(char c, int pid);
void	handle(int sig, siginfo_t *sa, void *unused);
void	ft_putnbr(int nb);
int		ft_atoi(const char *str);

#endif
