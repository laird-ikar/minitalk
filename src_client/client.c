/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:34:14 by bguyot            #+#    #+#             */
/*   Updated: 2023/04/28 10:36:30 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static void	sig_handler(int sig);
static void	send_message(char *msg, int pid_serv);
static void	send_signal(int pid, int sig);

int	main(int argc, char *argv[])
{
	int					pid_serv;

	if (argc != 3)
		return (ft_printf("Usage : ./client [PID] [message]\n"));
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
	{
		exit(1);
	}
	pid_serv = ft_atoi(argv[1]);
	send_message(argv[2], pid_serv);
	pause();
}

static void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("Acknowledgment of 0 received, message go sent.", 1);
		exit(0);
	}
}

static void	send_message(char *msg, int pid_serv)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (msg[i])
	{
		j = 8;
		c = msg[i];
		while (j--)
		{	
			if (c >> j & 1)
				send_signal(pid_serv, SIGUSR1);
			else
				send_signal(pid_serv, SIGUSR2);
		}
		i++;
	}
	j = 8;
	while (j--)
		send_signal(pid_serv, SIGUSR2);
}

static void	send_signal(int pid, int sig)
{
	kill(pid, sig);
	usleep(100);
}
