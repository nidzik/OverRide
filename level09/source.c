#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct content {
	char msg[140];
	char name[40];
	int len;
} cont;

void		secret_backdoor(void)
{
	char	buf[128];

	fgets(buf, 128, stdin);
	system(buf);
}

void		set_msg(struct content * cont)
{
	char	buf[1024];

	memset(buf, '\0', 128);
	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buf, 1024, stdin);
	strncpy(cont->msg, buf, cont->len);
}

void		set_username(struct content *cont)
{
	int		n;
	char	buf[128];

	memset(buf, '\0', 128);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(buf, 128, stdin);
	n = 0;
	while (1)
	{
		cont->name[n] = buf[n];
		if (n >= 40 || buf[n] == '\0')
			break ;
		n++;
	}
	printf(">: Welcome, %s", cont->name);
}

void		handle_msg(void)
{
	struct content cont;

	memset(buf + 140, '\0', 40);
	cont.len = 140;
	set_username(&cont);
	set_msg(&cont);
	puts(">: Msg sent!");
}

int		main(void)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------\n");
	handle_msg();
	return (0);
}
