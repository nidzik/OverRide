#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	int		n;

	puts("***********************************");
	puts("* \t     -Level00 -\t\t  *");
	puts("***********************************");
	printf("Password:");
	scanf("%d", &n);
	if (n == 0x149c) { // 0x149c == 5276
		puts("\nAuthenticated!");
		system("/bin/sh");
	} else {
		puts("\nInvalid Password!");
	}
	return (1);
}
