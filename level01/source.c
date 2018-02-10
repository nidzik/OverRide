#include <stdio.h>
#include <stdint.h>

char a_user_name[];





int verify_user_pass(char * pass)
{
char *st3 = "admin";
int i = 0;

while (i < 5 && pass[i] == st3[i])
{
i++;
}

uint8_t dl ;   // seta dl
if (pass[i] ==  st3[i])
        dl = 0;
else
        dl = 1;
return ((int)dl);
//uint8_t al = 1;   // setb al
}


int verify_user_name(void)
{
char *st = "verifying username....\n";
puts(st);

char *st2 = a_user_name;
char *st3 = "dat_wil";
int i = 0;

while (i < 7 && st2[i] && st3[i] && st2[i] == st3[i])
{
printf("%d", i);
i++;
}

uint8_t dl ;   // seta dl
if (i == 6)
        dl = 0;
else
        dl = 1;
printf("%d", (int)dl);

return ((int)dl);
//uint8_t al = 1;   // setb al

}

int main(int ac, char **av)
{
char str[28];

int i = 0;
while ( i < 17)
{
        str[i] = '\0';
        i++;
}
char *str2 = 0;
str2 = "********* ADMIN LOGIN PROMPT *********";
puts(str2);

char *str3 = "Enter Username: ";
printf(str3);

fgets(a_user_name, 256, stdin);

int j;
j = verify_user_name();
int ret;
if (j == 0)
{
        puts("Enter Password: ");
        fgets(str, 100 , stdin);
        int gg = verify_user_pass(str);
        ret = 0;
}
else
{
        char *str4 = "nope, incorrect username...\n";
        puts(str4);
        ret = 1;
}
return ret;
}
