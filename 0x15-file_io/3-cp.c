#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_file - A function checking whether files can be opened.
 * @file_from: first parameter of the file_from where to copy.
 * @file_to: Second parameter of the file_to copy to.
 * @argv: arguments vector being passed.
 * Return: Always 0.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	/* First check if the file_from couldnt be accessed */
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);

		exit(98);
	}

	/* Check if file to copy to couldn't be written to */

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);

		exit(99);
	}

}

/**
 * main - main function to check code.
 * @argc: first parameter of arguments.
 * @argv: second parameter arguments vector.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int file_from;
	int file_to;
	int err_close;
	ssize_t schars, wrt;
	char buff[1024];

	/* Check for the compatibility of available arguments */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");

		exit(97);
	}
	/* Source file opened for rdonly and file_to in wronly or create if absent*/
	file_from = open(argv[1], O_RDONLY);

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0064);

	/* Check whether the files were opened successfully*/
	error_file(file_from, file_to, argv);

	/* Read file_from and write to file_to till the end in 1024 bytes of chunks */
	schars = 1024;

	while (schars == 1024)
	{
		schars = read(file_from, buff, 1024);

		/* Check presence of error in reading the source file */
		if (schars == -1)

			error_file(-1, 0, argv);

		wrt = write(file_to, buff, 1024);

		/* Check presence of error writing to the destined file */

		if (wrt == -1)

			error_file(0, -1, argv);

	}
	/* Close both the destination and source files */

	err_close = close(file_from);

	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);

		exit(100);
	}

	err_close = close(file_to);

	if (err_close == -1)

	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);

		exit(100);
	}

	return (0);
}

