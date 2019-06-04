#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	a_user_name[100];

int		verify_user_name(void)
{
	puts("verifying username....\n");
	return (strncmp(a_user_name, "dat_wil", 7));
}

int		verify_user_pass(char *password)
{
	return (strncmp(password, "admin", 5));
}

int		main(int argc, char **argv)
{
	char	password[64];

	memset(a_user_name, '\0', 100);

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(a_user_name, 256, stdin); // shellcode

	if (verify_user_name(a_user_name) != 0) {
		puts("nope, incorrect username...\n");
		return (1);
	}

	puts("Enter Password: ");
	fgets(password, 100, stdin); // eip overflow

	if (verify_user_pass(password) == 0) {
		puts("nope, incorrect username...\n");
		return (1);
	}

	return (1);
}
