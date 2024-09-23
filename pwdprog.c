#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc , char* argv[])
{
	if(argc !=1)
	{
         	printf("Enter valid number of argyments");
		return -1;
	}

int size =50;
char * buf;

buf = getcwd(buf,size);

if (buf == NULL)
	printf("Can not get the full path of the directory \n");
else
	write (1,buf,size);
write (1,"\n ",1);


return 0;
}
