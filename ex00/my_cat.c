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

void my_cat(int argc, char** argv)
{
	char buf;
	int fd;
	int i = 0 + 1;

	while ( i < argc )
	{
		fd = open( argv[ i ], O_RDONLY );
		while ( read( fd, &buf, 1 ) != 0 ) // while the 1 current byte from the file descriptor fd into the buffer starting at buf is not null
			write( 1, &buf, 1 );
		close( fd );
		i++;
	}
}

int main( int argc, char** argv )
{
	my_cat( argc, argv );
	return 0;
}
