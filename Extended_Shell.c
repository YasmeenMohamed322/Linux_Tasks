#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


typedef struct 
{
	char variable_name [20];
	char value[20];
}variable;

variable v[20];
int vindex=0;

void set(char*name,char*value){
	strcpy(v[vindex].variable_name,name);
	strcpy(v[vindex].value,value);
	printf("%s = %s\n",v[vindex].variable_name,v[vindex].value);
	vindex++;	
}


void printlocal()
{
	for(int l =0 ; l < vindex; l++)
		printf("%s = %s\n",v[l].variable_name,v[l].value);
}

char* search_value(char *name)
{
 for (int l=0;l< vindex;l++)
 {
	 if(strcmp(v[l].variable_name,name)==0)
	 {
		return v[l].value;
	 }
 }
}
int main(int argc, char* argv[]){

	int status = 0;
	
	while(1)
	{
		int i =0;
		char buf[100];

		int flag = 0;
		do
		{
		printf("My Prompt > ");
		fgets(buf,100,stdin);
		}
		while(strcmp(buf,"\n")==0);
	
	
		argv[i]=strtok(buf, "  \n");
		while(argv[i]!=NULL)
		{
		printf("%d  %s\n",i,argv[i]);
			i++;
			argv[i] = strtok(NULL," \n");
		}
		argv[i]=NULL;

		int count=0;
		while(argv[count]!=NULL)
		{
			if (strcmp(argv[count], "=") ==0)
			{
			   char * variable = argv[count-1];
			   char*  value    = argv[count+1];
			   set (variable,value);
			   flag=1;
			   break;
		        }
			count++;
		}

		if (flag ==1)
		{
			continue;
		}

		if (strcmp(argv[0],"set")==0)
		{
			printlocal();
			continue;
		}

		if (strcmp(argv[0],"export")==0)
		{
			char* ret_value = search_value(argv[1]);
			setenv(argv[1], ret_value ,1);
			continue;
		}

		int ret_pid = fork();

		if(ret_pid < 0)
			printf("Fork Failed");
		else if(ret_pid > 0)
		{
			wait(&status);
		}
		else if(ret_pid == 0)
		{
			
			execvp(argv[0],argv);
			printf("exec Failed!\n");
		}

	}
return 0;
}
