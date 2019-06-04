#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int		clear_stdin(void)
{
	char	c;

	c = 0;
	while (1) {
		if ((c = getchar()) == 10) {
			return (c);
		}
	}
	return (0);
}

uint32_t	get_unum()
{
	unsigned int	n;

	fflush(stdout);
	scanf("%u", &n);
	clear_stdin();
	return (n);
}

int		store_number(char *ptr)
{
	int		number;
	int		index;

	printf(" Number: ");
	number = get_unum();
	printf(" Index: ");
	index = get_unum();
	if ((index % 3) == 0 || (number >> 24) == 0xb7) {
		puts(" *** ERROR! ***");
		puts("   This index is reserved for wil!");
		puts(" *** ERROR! ***");
		return (1);
	}
	ptr[index] = number;
	return (0);
}

int		main(int argc, char **argv, char **envp)
{
	char	str[20];
	int		buf[100];
	int		n;
	int		l;

	/* delete argv + envp */

	memset(str, '\0', 20);
	memset(buf, '\0', 100);

	printf("----------------------------------------------------\n"\
"  Welcome to wil's crappy number storage service!   \n"\
"----------------------------------------------------\n"\
" Commands:                                          \n"\
"    store - store a number into the data storage    \n"\
"    read  - read a number from the data storage     \n"\
"    quit  - exit the program                        \n"\
"----------------------------------------------------\n"\
"   wil has reserved some storage :>                 \n"\
"----------------------------------------------------\n");

	while (1) {
		printf("Input command: ");
		fgets(str, 20, stdin);
		l = strlen(str);
		cmd[l - 1] = '\0';

		if (strncmp(str, "store", 5) == 0) {
			n = store_number(data);
		} else if (strncmp(str, "read", 4) == 0) {
			n = read_number(data);
		} else if (strncmp(str, "quit", 4) == 0) {
			return (0);
		}
		
		if (n == 1) {
			printf(" Failed to do %s command\n", str);
		} else {
			printf(" Completed %s command successfully\n", str);
		}

		memset(str, '\0', 20);
	}
	return (0);
}
