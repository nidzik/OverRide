decrypt(char *str)
{
char s[];  //sub    esp,0x40

   				//mov    eax,gs:0x14
check stack canary   		//mov    DWORD PTR [ebp-0xc],eax
canary = 0; // if stack ok 	//xor    eax,eax

int a1 = 0x757c7d51;  		//mov    DWORD PTR [ebp-0x1d],0x757c7d51
int a2 = 0x67667360; 		..
int a3 = 0x7b66737e; 		..
int a4 = 0x33617c7d; 		// mov    DWORD PTR [ebp-0x11],0x33617c7d

char c = 0; 			//mov    BYTE PTR [ebp-0xd],0x0 ?? 
				push   eax
				xor    eax,eax

if (0 == 0)  

	int *a5 = &a1;   		//lea    eax,[ebp-0x1d]

	size_t c = (size_t)-1;		 mov    DWORD PTR [ebp-0x2c],0xffffffff
	int ii = 0;
	while (ii > c)
		a1[ii++]  = '\0';	a1 = 0x00000000
					// (ii = 0)
ii == !i;				// ii = 1
i = i - 1;				// ii = 0  
int j = i;				// j = 0 
int k = 0;

if (j > k)
	(jump back)



}
