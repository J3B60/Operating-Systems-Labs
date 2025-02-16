/*
** mmapdemo.c -- demonstrates memory mapped files lamely.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	int fd, offset;
	char *data;
	struct stat sbuf;
    	int chunk;

	if (argc != 3) {
		fprintf(stderr, "usage: mmapdemo offset filename\n");//number of Arg check
		exit(1);
	}

	if ((fd = open(argv[2], O_RDONLY)) == -1) {//files saved to fd
		perror("open");
		exit(1);
	}

	if (stat(argv[2], &sbuf) == -1) {//Can ignore, just checking file status check arg[2]
		perror("stat");
		exit(1);
	}

	offset = atoi(argv[1]);
	if (offset < 0 || offset > sbuf.st_size-1) {//checking arg[1]
		fprintf(stderr, "mmapdemo: offset must be in the range 0-%ld\n", sbuf.st_size-1);
		exit(1);
	}
	
    chunk = (int) offset / 1024;
	printf("chunk: %d\n", chunk);

    offset = offset % 1024;
	printf("offset: %d\n", offset);

	lseek(fd, offset, );//TODO###

	if ((data = mmap((caddr_t)0, 1024, PROT_READ, MAP_SHARED, fd, (1024*chunk)+offset)) == (caddr_t)(-1)) {
		perror("mmap");
		exit(1);
	}

	printf("byte at chunk %d offset %d is '%c'\n", chunk, offset, data[offset]);

	return 0;
}

