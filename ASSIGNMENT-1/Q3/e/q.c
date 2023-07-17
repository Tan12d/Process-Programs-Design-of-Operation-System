#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

	if (fork() || fork())
		fork();
  
	printf(" 1 ");

	return 0;
}

