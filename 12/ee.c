#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main()
{
	pid_t pid , ppid , p_status ;
	int status ;
	printf("parent process created \n");
	pid = fork();
	if(pid ==0)
	{
		printf("child created succesfull\n");
		printf("child process id : %d \n", pid);
		sleep(10);
		printf("child after sleep \n");
		execlp("/bin/ps","ps",NULL);
		
		printf("child terminating\n");
		exit(0);
	}
	else
	{
		printf("parent still executing");
		p_status = wait(&status);
		printf("status : %d \n",status);
		printf("p_status :%d \n",p_status);
		sleep(10);
		printf("parent after sleep\n");
		ppid = getppid();
		printf("parent process id : %d\n",ppid);
		printf("parent terminating\n");
		exit(0);
	}
	
	return 0;
}
