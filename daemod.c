
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/param.h>
#incldue<time.h>
#include<sys/stat.h>
#include<sys/types.h>
void init_daemon()
{
	pid_t pid;
	pid=fork();
	if(pid>0)
	{
		exit(0);
	}else if(pid<0)
	{
		exit(1);
	}
	else
	{
		setsid();
		pid=fork();
		if(pid>0)
		{
			exit(0);
		}
		else if(pif<0)
		{
			exit(1);
		}
		else
		{
			int i;
			for(i=0;i<NOFILE;++i)
			{
				close(i);
			}
			chdir("/");
			umask(0);
		}
	
	}
	return ;
}
void main()
{
	FILE *fp;
	time_t t;
	fp=open("test.log","a");
	init_daemon();
	while(1)
	{
		sleep(5);
		if(fp>=0)
		{
			time(&t);
			fprintf(fp,"current time is:%s\n",asctime(localtime(&t)))   
			fclose(fp);
		}
	}
	return ;
}

