/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 04:56:47 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/14 16:16:16 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(t_data arg, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		arg.b = (c & (1 << i));
		if (arg.b)
		{
			if (kill(arg.pid, SIGUSR1) == -1)
			{
				ft_putstr_fd("check pid", 1);
				exit(1);
			}
		}
		else
		{
			if (kill(arg.pid, SIGUSR2) == -1)
			{
				ft_putstr_fd("check pid", 1);
				exit(1);
			}
		}
		usleep(500);
		i++;
	}
}

void handler(int sig)
{
	(void)sig;
	ft_putstr_fd("Message Sent!!!", 1);	
}

int	main(int ac, char **av)
{
	t_data	arg;
	size_t	x;

	if (ac == 3)
	{
		arg.pid = ft_atoi(av[1]);
		if (arg.pid <= 0)
			return (1);
		x = 0;
		signal(SIGUSR1, handler);
		if (!av[2][x])
			ft_putstr_fd("Empty string\0", 1);
		while (av[2][x])
		{
			send_bit(arg, av[2][x]);
			x++;
		}
		send_bit(arg, av[2][x]);
	}
	else
		ft_putstr_fd("check number of argiments", 1);
	return (0);
}
