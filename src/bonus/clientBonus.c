/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientBonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:55:22 by apangraz          #+#    #+#             */
/*   Updated: 2021/12/22 13:55:47 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniTalk.h"

static void	confirmHandler(int signum)
{
	(void)signum;
	if (signum == SIGUSR1)
	{
		ft_printf("Message sent and recieved successfully!\n");
		exit(0);
	}
}

static void	sendMsg(int serverPid, char byte)
{
	int	bitShift;

	bitShift = 0;
	while (bitShift <= 7)
	{
		if ((byte >> bitShift) & 1)
		{	
			if (kill(serverPid, SIGUSR1) == -1)
				ft_printf("failed to send SIGUSR1 msg\n");
		}		
		else
		{	
			if (kill(serverPid, SIGUSR2) == -1)
				ft_printf("failed to send SIGUSR2 msg\n");
		}
		bitShift++;
		usleep(150);
	}
}

static int	argChecker(int counter)
{
	if (counter != 3)
	{
		ft_printf("CLIENT: Invalid number of arguments\n");
		exit(1);
	}
	return (0);
}

int	main(int argc, char **av)
{
	int					sPid = ft_atoi(av[1]);
	struct sigaction	cntCiggie;
	char				*msg = av[2];
	int					i = 0;

	argChecker(argc);
	msg[strlen(msg) + 1] = '\0';
	cntCiggie.sa_handler = &confirmHandler;
	sigemptyset(&cntCiggie.sa_mask);
	while (1)
	{	
		sigaction(SIGUSR1, &cntCiggie, 0);
		while (msg[i] != '\0')
		{
			sendMsg(sPid, msg[i++]);
		}
		if (msg[i] == '\0')
			sendMsg(sPid, msg[i]);
		pause();
	}
	return (0);
}
