#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		a;
	short	b;
	int		pos;
	char	b1[100] = {0};
	char	b2[41] = {0};
	char	b3[100] = {0};

	a = 0;
	b = 0;
	pos = 0;

	a = fopen("/home/users/level03/.pass", "r");
	if (a == 0) {
		fwrite("ERROR: failed to open password file\n", 1, 36, 2);
		exit(1);
	}

	b = fread(b2, 1, 41, a);
	pos = strcspn(b2, "\n");
	b2[pos] = '\0';

	if (b == 41) {
		fclose(a);

		puts("===== [ Secure Access System v1.0 ] =====");
		puts("/***************************************\\");
		puts("| You must login to access this system. |");
		puts("\\**************************************/");

		printf("--[ Username: ");
		fgets(b1, 100, 0);
		pos = strcspn(b1, "\n");
		b1[pos] = '\0';

		printf("--[ Password: ");
		fgets(b3, 100, 0);
		pos = strcspn(b3, "\n");
		b3[pos] = '\0';

		puts("*****************************************");

		if (strncmp(b2, b3, 41) == 0) {
			printf("Greetings, %s!\n", b1);
			system("/bin/sh");
			return (0);
		} else {
			printf(b1); // exploit
			puts(" does not have access!");
			exit(1);
		}
	}
	return (0);
}
