/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 04:05:25 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/02/14 15:38:18 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	int	pid;
	int	b;
	int	mess;
}		t_data;

void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);

#endif