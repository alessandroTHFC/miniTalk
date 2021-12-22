#include "miniTalk.h"

static void	confirmHandler(int signum)
{
	(void)signum;
	if(signum == SIGUSR1)
	{
		ft_printf("Message sent and recieved successfully!\n");
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
				ft_printf("failed to send SIGUSR1 msg\n");
		}		
		else
		{	
			if(kill(serverPid, SIGUSR2) == -1)
				ft_printf("failed to send SIGUSR2 msg\n");
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
		printf("CLIENT: invalid number of arguments\n");
		exit(1);
	}
	msg = av[2];
	msg[strlen(msg) + 1] = '\0';
	cntCiggie.sa_handler = &confirmHandler;
	sPid = ft_atoi(av[1]);
	sigemptyset(&cntCiggie.sa_mask);
	i = 0;
	while(1)
	{	
		sigaction(SIGUSR1, &cntCiggie, 0);
		while(msg[i] != '\0')
		{
			sendMsg(sPid, msg[i++]);
		}
		if(msg[i] == '\0')
			sendMsg(sPid, msg[i]);
		pause();
	}
	return(0);
}
