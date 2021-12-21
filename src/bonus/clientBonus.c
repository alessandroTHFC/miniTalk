#include "miniTalk.h"

static void	confirmHandler(int signum)
{
	(void)signum;
	if(signum == SIGUSR1)
	{
		ft_printf("Message sent and recieved successfully!");
		exit(0);
	}
}

static void	sendMsg(int	serverPid, char byte)
{
	int	bitShift;

	bitShift = 0;
	while(bitShift <= 7)
	{
		if((byte >> bitShift) & 1)
		{	
			if(kill(serverPid, SIGUSR1) == -1)
				ft_printf("failed to send SIGUSR1 msg");
		}		
		else
		{	
			if(kill(serverPid, SIGUSR2) == -1)
				ft_printf("failed to send SIGUSR2 msg");
		}
		bitShift++;
		usleep(150);
	}
}

int	main(int argc, char **av)
{
	int					sPid;
	struct sigaction	cntCiggie;
	char				*msg;
	int					i;

	if(argc != 3)
	{
		printf("CLIENT: invalid number of arguments/n");
		exit(1);
	}
	msg = av[2];
	cntCiggie.sa_handler = &confirmHandler;
	sPid = ft_atoi(av[1]);
	sigemptyset(&cntCiggie.sa_mask);
	i = 0;
	while(1)
	{	
		while(msg[i] != 0)
		{
			sendMsg(sPid, msg[i++]);
		}
		pause();
	}
	return(0);
}
