#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int		auth(char *buf, int n)
{
	size_t	len;
	int		tmp1;
	int		tmp2;
	int		eax;
	int		ecx;
	int		edx;

	buf[strcspn(buf, "\n")] = '\0';
	len = strnlen(buf, 32);
	if (len <= 5)
		return (1);

	if (ptrace(PT_TRACE_ME, 0, 1, 0) == -1)
	{
		puts("\033[32m.---------------------------.");
		puts("\033[31m| !! TAMPERING DETECTED !!  |");
		puts("\033[32m'---------------------------'");
		return (1);
	}

	eax = *(buf + 3) - '0';
	eax ^= 0x1337;
	eax += 0x5eeded;
	tmp1 = eax;

	for (tmp2 = 0 ; tmp2 < len ; tmp2++) {
		eax = tmp2 + (int)buf;
		eax = (int)((eax << 4) >> 4);

		if (eax <= 31)
			return (1);

		ecx = eax | tmp1;
		edx = 0x88233b2b * ecx;
		eax = ecx - edx;
		eax = (((eax >> 1) + edx) >> 10) * 0x539;
		tmp1 += ecx - eax;
	}
	if (tmp1 == n)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char	buf[32];
	int		n;

	puts("***********************************");
	puts("*\t\tlevel06\t\t  *");
	puts("***********************************");
	printf("-> Enter Login: ");

	fgets(buf, 32, 0);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");

	scanf("%u", &n);

	if (auth(buf, n) != 0)
		return (1);

	puts("Authenticated!");
	system("/bin/sh");
	return (0);
}
