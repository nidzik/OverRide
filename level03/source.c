#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int		decrypt(int n)
{
	char	s[] = "Q}|u`sfg~sf{}|a3";
	int		i;
	int		l;

	l = strlen(s);
	while (i < l) {
		s[i] ^= n;
		i++;
	}

	if (strcmp(str, "Congratulations!") == 0) {
		system("/bin/sh");
	} else {
		puts("\nInvalid Password");
	}
	return (0);
}

void		test(int a, int b)
{
	int		n;

	n = b - a;
	switch (n) {
		case 1: decrypt(n); break;
		case 2: decrypt(n); break;
		case 3: decrypt(n); break;
		case 4: decrypt(n); break;
		case 5: decrypt(n); break;
		case 6: decrypt(n); break;
		case 7: decrypt(n); break;
		case 8: decrypt(n); break;
		case 9: decrypt(n); break;
		case 16: decrypt(n); break;
		case 17: decrypt(n); break;
		case 18: decrypt(n); break;
		case 19: decrypt(n); break;
		case 20: decrypt(n); break;
		case 21: decrypt(n); break;
		default: decrypt(rand()); break;
	}
}

int		main(int argc, char **argv)
{
	int		n;

	srand(time(NULL));
	puts('***********************************');
	puts("*\t\tlevel03\t\t**");
	puts('***********************************');
	printf("Password:");
	scanf("%d", &n);
	test(n, 0x1337d00d); // 0x1337d00d = 322424845
	return (0);
}
