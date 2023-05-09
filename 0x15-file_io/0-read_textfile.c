#include "main.h"

/**
 * read_textfile - reads a text file and prints it
 * @filename: the name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, rd;
	char *buf;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters + 1));
	if (!buf)
	{
		close(fd);
		return (0);
	}

	rd = read(fd, buf, letters);
	if (rd == -1)
	{
		close(fd);
		free(buf);
		return (0);
	}

	buf[rd] = '\0';
	printf("%s", buf);

	close(fd);
	free(buf);

	return (rd);
}
