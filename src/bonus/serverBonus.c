#include "miniTalk.h"

void	sigHandler(int signum, siginfo_t *siginfo, void *unused)
{	
	(void) unused;
	static unsigned char bitValue = 0;
	static int	bitShift = 0;
	if(signum == SIGUSR1)
		bitValue |= (1 << bitShift);
	bitShift++;
	if(bitShift == 8)
	{	
		ft_printf("%c", bitValue);
		if(!bitValue)
			kill(siginfo->si_pid, SIGUSR1);
		bitValue = 0;
		bitShift = 0;

	}	
}

void	welcomeMsg(void)
{
	pid_t	pid;
	pid = getpid();
	ft_printf("\t\t>>Server Up and Running<<\n\t\t>>Waiting for Client...<<\n");
	ft_printf("\t\t  Process ID is: %i\n", pid);
	ft_printf("\t   >>To run use ./client PID ""mesage""<<\n");

}

int	main(void)
{
	struct sigaction	ciggie;

	sigemptyset(&ciggie.sa_mask);
	ciggie.sa_flags = SA_SIGINFO;
	ciggie.sa_sigaction = &sigHandler;
	welcomeMsg();	
	while(1)
	{
		if((sigaction(SIGUSR1, &ciggie, 0)) == -1)
			ft_printf("SIGUSR1 Error\n");
		if((sigaction(SIGUSR2, &ciggie, 0)) == -1)
			ft_printf("SIGUSR2 Error\n");
		pause();
	}
	return(0);
}
