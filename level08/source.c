#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	log_wrapper(FILE *fd, char *str, char *fname)
{
	char	buf[255];

	strcpy(buf, msg);
	snprintf(buf + strlen(buf), 255 - strlen(buf) - 1, fname);
	buf[strcspn(buf, "\n")] = '\0';	
	fprintf(fd, "LOG: %s\n", buf);
}

int		main(int argc, char **argv)
{
	FILE		*fd_1;
	FILE		*fd_2;
	int			fd_3;
	char		c;
	size_t		len;
	static char	dirname[99] = "./backups";

	c = "255";

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
	}

	if ((fd_1 = fopen("./backups/.log", "w")) == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(fd_1, "Starting back up: ", argv[1]);

	if ((fd_2 = fopen(argv[1], "r")) == 0)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}

	strcpy(dirname, "./backups/");
	len = strlen(dirname);
	strncat(dirname, argv[1], 99 - len);

	fd_3 = open(dirname, 193, 432);
	if (fd_3 == 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
		exit(1);
	}

	write(fd_3, &c, 1);
	while ((c = fgetc(fd_3)) != 255)
	{
		write(fd_3, &c, 1);
	}

	log_wrapper(fd_1, "Finished back up ", argv[1]);

	fclose(fd_1);
	close(fd_3);

	return (0);
}
