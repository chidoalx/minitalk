/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 04:00:45 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/14 16:11:52 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	write_byte(int sig, siginfo_t *s, void *contest)
{
	static int	bit;
	static int	byte;
	static int	pid;

	(void)contest;
	if (pid != s->si_pid)
	{
		pid = s->si_pid;
		bit = 0;
		byte = 0;
	}
	if (sig == SIGUSR1)
		byte = (byte | (1 << bit));
	bit++;
	if (bit == 8)
	{
		if (!byte)
			kill(s->si_pid, SIGUSR1);
		write(1, &byte, 1);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_putstr_fd("+-----------+\n+   ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("   +\n+-----------+\n", 1);
	write(1, "\n", 1);
	sa.sa_sigaction = write_byte;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	// if (mess == 1)
	// 	kill(pid, SIGUSR2);
	return (0);
}
