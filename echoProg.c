#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (int argc,char* argv[])
{
	int char_count = 1;
	
	while(char_count < argc)
	{
	   
            int size = strlen(argv[char_count]); 
	    int flag= write(1,argv[char_count],size);
	    if(flag == -1)
	    printf("Error printing on stdout");
	    write (1," ",1);
	    char_count++;
	}
	write(1,"\n",1);
	return 0;
}
