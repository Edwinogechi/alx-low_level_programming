#include "main.h"

/**
 * append_text_to_file - Function that appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The null-terminated string to add to the end of the file.
 *
 * Return: If success 1, on failure or filename is NULL -1.
 *         If the file is absent or the user lacks write permissions -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int fletters;
	int rwr;

	/* Check if filename and content of text are NULL */
	if (filename == NULL)
	{
		return (-1);
	}

	/* Open the file to append the text into it */

	fd = open(filename, O_WRONLY | O_APPEND);

	if (text_content != NULL)
	{
		for (fletters = 0; text_content[fletters]; fletters++)
			;

		rwr = write(fd, text_content, fletters);

		if (rwr == -1)

			return (-1);
	}

	/* Return success after closing the file */

	close(fd);

	return (1);
}

