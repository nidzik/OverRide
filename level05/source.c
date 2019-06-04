#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(void)
{
	int		n;
	char	buf[100];

	n = 0;
	fgets(buf, 100, stdin);
	n = 0;
	while (1)
	{
		if (buf[n] >= 64 && buf[n] <= 90)
			buf[n] = buf[n] ^ 32;
		n += 1;
		if (n >= strlen(buf))
			break ;
	}
	printf(buf); // exploit
	exit(0);
}
