#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

/**
 * check_arguments - checks if the arguments are valid or not
 * @argv: array of arguments
 * @argc: number of arguments
 *
 * Return: 0
 */

void check_arguments(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * read_write_files - reads from file_from and writes file_to
 *
 * @file_from: file to read from
 * @file_to: file to write to
 *
 * Return: 0
 */

void read_write_files(char *file_from, char *file_to)
{
	int fd_from, fd_to, ret = 0;
	ssize_t num_read, num_written;
	char buf[1024];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
	}
	while ((num_read = read(fd_from, buf, 1024)) > 0)
	{
		num_written = write(fd_to, buf, num_read);
		if (num_written != num_read || num_written == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			ret = 99;
			break;
		}
	}
	if (num_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		ret = 98;
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		ret = 100;
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		ret = 100;
	}
}

/**
 * main - copies the content of a file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	check_arguments(argc, argv);
	read_write_files(argv[1], argv[2]);
	return (0);
}
