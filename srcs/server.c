/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/28 10:48:47 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/server.h"

static void	sig_handler(int sig, siginfo_t *info, void *context);

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("%d\n", pid);
	action.sa_sigaction = sig_handler;
	action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &action, 0))
	{
		exit(1);
	}
	if (sigaction(SIGUSR2, &action, 0))
	{
		exit(1);
	}
	while (1)
		pause();
}

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_count = 0;
	static char	buffer[BUFFER_SIZE];

	(void)context, (void) info;
	c <<= 1;
	c |= 0b1 & (signum == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		buffer[ft_strlen(buffer)] = c;
		if (c == '\0' || ft_strlen(buffer) == BUFFER_SIZE)
		{
			write(1, buffer, ft_strlen(buffer));
			ft_bzero(buffer, BUFFER_SIZE);
			if (!c)
			{
				kill(info->si_pid, SIGUSR1);
				write(1, "\n", 1);
			}
		}
		c = 0;
		bit_count = 0;
	}
}
