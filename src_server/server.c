/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:34:18 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/18 15:43:41 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

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
		perror("Error :");
		exit(1);
	}
	if (sigaction(SIGUSR2, &action, 0))
	{
		perror("Error :");
		exit(1);
	}
	while (1)
		pause();
}

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 8;

	c |= (signum == SIGUSR1);
	i--;
	if (i == 0)
	{
		if (c != 0)
			ft_putchar_fd(c, 1);
		else
		{
			kill(info->si_pid, SIGUSR1);
			ft_putchar_fd('\n', 1);
		}
		c = 0;
		i = 8;
	}
	else
		c <<= 1;
	(void) context;
}
