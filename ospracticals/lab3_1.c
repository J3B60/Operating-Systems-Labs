#include <stdio.h>
void main(){
	printf("Process ID is: %d\n", getpid());
	printf("Parent process ID is: %d\n", getppid());
	sleep(120); /* sleeps for 2 minutes*/
	printf("I am awake.\n");
}
