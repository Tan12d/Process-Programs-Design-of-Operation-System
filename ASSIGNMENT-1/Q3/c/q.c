#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t c1,c2;
  c2=0;
  c1 = fork(); 
       	
  if (c1 == 0)
	    c2 = fork(); 

  if (c2 > 0)
  		fork();

	printf(" 1");
  
	return 0; 
}

