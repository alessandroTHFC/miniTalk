#include "miniTalk.h"

int	main(int argc, char **av)
{
	int	pid;

	if(argc != 3)
	{
		printf("CLIENT: invalid number of arguments/n");
		exit(1);
	}
	pid = ft_atoi(av[1]);
	kill(pid, SIGUSR1);
	return(0);
}
