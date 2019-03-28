#include <stdio.h>
int main(int argc, char *argv[]){
	unsigned long page, offset, address;
	if(argc != 2) exit(1);
	address = atoll(argv[1]);
	
	page = address >> 20;		/*calculating pages number*/
	offset = address & 0xfffff; 	/*calculating remaining offset*/
	
	printf("The address %lu contains: \n", address);
	printf("page number = %lu\n", page);
	printf("offset = %lu\n", offset);
	return 0;
}
