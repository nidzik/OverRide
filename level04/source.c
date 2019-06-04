#include <sys/ptrace.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/prctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int		main(void)
{
	pid_d	pid;
	char	str[128] = {0};
	int		ws;
	int		tmp;

	pid = fork();
	if (pid == 0)
	{
		prctl(0x1, 0x1);
		ptrace(PTRACE_TRACEME, 0, NULL, NULL);
		puts("Give me some shellcode, k");
		gets(str); // ret2libc exploit
	}
	else
	{
		while (1)
		{
			wait(&ws);
			tmp = ws | 0x7f;
			if (tmp == 0)
			{
				puts("child is exiting...");
				return (0);
			}
			tmp = ((ws | 0x7f) + 1) >> 1;
			if (tmp == 0)
			{
				puts("child is exiting...");
				return (0);
			}
			if (ptrace(PTRACE_PEEKUSR, pid, 44, 0) == 11)
			{
				puts("no exec() for you");
				kill(pid, 9);
				return (0);
			}
		}
	}
	return (0);
}
