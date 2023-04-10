#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file print to STDOUT (POSIX).
 * @filename: text file to read
 * @letters: number of letters to be read
 * Return: the actual number of letters to read and print,
 *        0 if an error occured.
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	char *buffer;
	ssize_t bytes_read;
	ssize_t bytes_written;

	/* Open the file for reading */

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0); /* Error read */
	}

	/* Allocate memory to the buffer, read and write to STDOUT_FILENO */

	buffer = malloc(sizeof(char) * letters);

	bytes_read = read(fd, buffer, letters);

	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);


	/* Free buffer memory and close file descriptor */

	free(buffer);

	close(fd);

	return (bytes_written);
}

