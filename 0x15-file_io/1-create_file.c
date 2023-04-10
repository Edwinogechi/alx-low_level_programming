#include "main.h"

/**
 * create_file - Creates a file and writes the given content
 * @filename: Pointer to the name of the file to be created.
 * @text_content: Pointer to the string to write to the given file.
 *
 * Return: Returns 1 on success,
 *         -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	/* Check if filename is NULL and text_content is not */

	int fd = 0;
	int content_len = 0;
	int bytes_written = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (content_len = 0; text_content[content_len];)
			content_len++;
	}

	/* Open file with flags for wronly,creat,trunc Set permissions to rw------- */
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	/* Get text content length and write it to the file and check if it fails */

	bytes_written = write(fd, text_content, content_len);

		if (fd == -1 || bytes_written == -1)
		{
	/* Return -1 if opening fails */
			return (-1);
		}

	/* Close the file and return 1 on success */

	close(fd);

	return (1);
}
