#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char*argv[])
{
char buf[100];
int count=0;

if(argc!=3)
{
	printf("enter a valid number of arguments\n");
	return -1;
}

int fp1 = open(argv[1],O_RDONLY);
if(fp1==-1)
{
	printf("error opening the source file");
	return -1;
}
int fp2 = open(argv[2],O_WRONLY|O_CREAT);
if(fp2==-1)
{
	printf("error opening the destination file");
	return -1;
}
	int wFlag=0;
while((count = read(fp1,buf,100))!=0)
	{
		wFlag=write(fp2,buf,count);
	if(wFlag==-1)
	{
		printf("error writing to the file");
	break;
	}	
	}
close(fp1);

close(fp2);

}


