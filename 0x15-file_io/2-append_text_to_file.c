#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: the name of the file
 * @text_content: the content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, res_write, i;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	for (i = 0; text_content[i] != '\0'; i++)
		;

	res_write = write(fd, text_content, i);
	close(fd);

	if (res_write == -1)
		return (-1);

	return (1);
}
