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
	int outcome, file_len, w = 0;

	/* Check if filename and content of text are NULL */
	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		for (file_len = 0; text_content[file_len];)

			file_len++;
	}
	/* Open the file to append the text into it */
	outcome = open(filename, O_WRONLY | O_APPEND);

	w = write(outcome, text_content, file_len);

	/* Return -1 if it fails to open the file */
	if (outcome == -1 || w == -1)
	{
		return (-1);
	}

	/* Return success after closing the file */

	close(outcome);

	return (1);
}
