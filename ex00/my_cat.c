/*
**
** QWASAR.IO -- my_cat
**
** @param {int} argc
** @param {char**} argv
**
** @return {void}
**
*/

#include <fcntl.h> // https://pubs.opengroup.org/onlinepubs/007904875/basedefs/fcntl.h.html https://man7.org/linux/man-pages/man2/fcntl.2.html
#include <unistd.h> // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html
//#include <stddef.h> // https://pubs.opengroup.org/onlinepubs/009695399/basedefs/stddef.h.html https://pubs.opengroup.org/onlinepubs/009604599/basedefs/sys/types.h.html
//#include <stdio.h> // https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html https://www.ibm.com/docs/en/zos/2.3.0?topic=files-stdioh-standard-input-output

void my_cat(int argc, char** argv)
{
	char buf;
	int fd;// = open(argv[i], O_RDONLY); //FILE* fd = fopen(argv[i], r); // https://linux.die.net/man/3/open https://www.cprogramming.com/tutorial/cfileio.html https://www.cprogramming.com/tutorial/cfileio.html
	int i = 0 + 1;

	while ( i < argc )
	{
		fd = open(argv[i], O_RDONLY);
		while ( read(fd, &buf, 1) != 0 ) // while the 1 current byte from the file descriptor fd into the buffer starting at buf is not null
			write(1, &buf, 1);
		close(fd);
		i++;
	}
}

int main(int argc, char** argv)
{
	my_cat(argc, argv);
	return 0;
}

