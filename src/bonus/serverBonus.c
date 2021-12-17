#include "miniTalk.h"

void	handleSig1(int signum)
{
	printf("Signal %d recieved.\n", signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID is: %i", pid);
	signal(SIGUSR1, handleSig1);
	while(1)
		pause();
}
