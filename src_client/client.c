/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 07:34:14 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/18 10:39:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

static void	sig_handler(int sig);
static void	send_message(char *msg, int pid_serv);

int	main(int argc, char *argv[])
{
	int		pid_serv;

	if (argc != 3)
		return (ft_printf("Usage : ./client [PID] [message]\n"));
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
	{
		perror("Error :");
		exit(1);
	}
	pid_serv = ft_atoi(argv[1]);
	send_message(argv[2], pid_serv);
	//pause();
}

static void	sig_handler(int sig)
{
	(void) sig;
		ft_printf(" > Your message has been correctly shreked to \
the server my dude ! \\_ÒwÓ_/\n");

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
				kill(pid_serv, SIGUSR1);
			else
				kill(pid_serv, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	j = 8;
	while (j--)
	{
		kill(pid_serv, SIGUSR2);
		usleep(100);
	}

}
