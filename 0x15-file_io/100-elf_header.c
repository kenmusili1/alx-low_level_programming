#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <elf.h>

#define ELF_MAGIC_SIZE      16
#define ELF_CLASS_SIZE      1
#define ELF_DATA_SIZE       1
#define ELF_VERSION_SIZE    1
#define ELF_OSABI_SIZE      1
#define ELF_ABIVERSION_SIZE 1
#define ELF_TYPE_SIZE       2
#define ELF_ENTRY_ADDR_SIZE 8
#define EXIT_FAILURE_ELF    98

/**
 * Function to read ELF header data from the file descriptor
 *@fd: read
 *@char: Arguments
 *@size_t: size
 *
 * return (0)
 *
 */

int read_elf_header(int fd, char *buffer, size_t size)
{
	ssize_t bytes_read = read(fd, buffer, size);
	if (bytes_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE_ELF);
	}
	return bytes_read;
}

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

void display_elf_header(char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE_ELF);
	}

	char magic[ELF_MAGIC_SIZE];
	read_elf_header(fd, magic, ELF_MAGIC_SIZE);

	if (magic[0] != 0x7f || magic[1] != 'E' || magic[2] != 'L' || magic[3] != 'F')
	{
		fprintf(stderr, "Error: Not an ELF file.\n");
		exit(EXIT_FAILURE_ELF);
	}

	char elf_class;
	read_elf_header(fd, &elf_class, ELF_CLASS_SIZE);

	char elf_data;
	read_elf_header(fd, &elf_data, ELF_DATA_SIZE);

	char elf_version;
	read_elf_header(fd, &elf_version, ELF_VERSION_SIZE);

	char elf_osabi;
	read_elf_header(fd, &elf_osabi, ELF_OSABI_SIZE);

	char elf_abiversion;
	read_elf_header(fd, &elf_abiversion, ELF_ABIVERSION_SIZE);

	uint16_t elf_type;
	read_elf_header(fd, (char *)&elf_type, ELF_TYPE_SIZE);

	uint64_t entry_addr;
	read_elf_header(fd, (char *)&entry_addr, ELF_ENTRY_ADDR_SIZE);

	close(fd);

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < ELF_MAGIC_SIZE; i++)
		printf("%02x ", (unsigned char)magic[i]);
	printf("\n");
	printf("  Class:                             ELF%d\n", elf_class == 1 ? 32 : 64);
	printf("  Data:                              %s endian\n", elf_data == 1 ? "little" : "big");
	printf("  Version:                           %d (current)\n", elf_version);
	printf("  OS/ABI:                            ");
	switch (elf_osabi)
	{
	case 0x00:
		printf("UNIX - System V\n");
		break;
	case 0x06:
		printf("UNIX - Solaris\n");
		break;
	case 0x53:
		printf("<unknown: 53>\n");
		break;
	default:
		printf("Unknown OS/ABI\n");
		break;
	}
	printf("  ABI Version:                       %d\n", elf_abiversion);
	printf("  Type:                              ");
	switch (elf_type)
	{
	case 0x01:
		printf("REL (Relocatable file)\n");
		break;
	case 0x02:
		printf("EXEC (Executable file)\n");
		break;
	case 0x03:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("Unknown type\n");
		break;
	}
	printf("  Entry point address:               0x%lx\n", entry_addr);
}

/**
 * main - copies the content of a file to another
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(EXIT_FAILURE_ELF);
	}

	display_elf_header(argv[1]);

	return 0;
}
