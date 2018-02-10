int main(int ac, char** av)
{
puts("***********************************");
puts("* 	     -Level00 -		  *");
puts("***********************************");
char *var = "password:";
printf("%s", var);
int c;
scanf("%d", c);
if (c == 5276)
{
	puts("\nAuthenticated!");
	system("/bin/sh");
	return (0);
}
else
{
	puts("\nInvalid Password!");
	return (1);
}
}
