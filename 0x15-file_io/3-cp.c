#include "main.h"
/**
 * _checker - check if file is NULL
 * @file1: file1
 * @file2: file2
 */
void _checker(char *file1, char *file2)
{
	if (file1 == NULL)
		read_err(file1);
	if (file2 == NULL)
		write_err(file2);
}
/**
 * read_err - check if error on file read
 * @file: pointer to file
 */
void read_err(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
	exit(98);
}
/**
 * write_err - check if error on file write
 * @file: pointer to file
 */
void write_err(char *file)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
	exit(99);
}
/**
 * close_err - check if error on file close
 * @fd: file descriptor
 */
void close_err(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}
/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 success, -1 fail
 */
int main(int argc, char *argv[])
{
	int file_i, file_o, file_i_read, file_o_write, file_i_close,
		file_o_close;
	char *buffer;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	_checker(argv[1], argv[2]);
	file_i = open(argv[1], O_RDONLY);
	if (file_i == -1)
		read_err(argv[1]);
	file_o = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, mode);
	if (file_o == -1)
		write_err(argv[2]);
	buffer = malloc(BUFSIZE * sizeof(char));
	if (buffer == NULL)
		return (1);
	file_i_read = read(file_i, buffer, BUFSIZE);
	if (file_i_read == -1)
		read_err(argv[1]);
	while (file_i_read > 0)
	{
		file_o_write = write(file_o, buffer, file_i_read);
		if (file_o_write == -1)
			write_err(argv[2]);
		file_i_read = read(file_i, buffer, BUFSIZE);
		if (file_i_read == -1)
			read_err(argv[1]);
	}
	file_i_close = close(file_i);
	if (file_i_close == -1)
		close_err(file_i_close);
	file_o_close = close(file_o);
	if (file_o_close == -1)
		close_err(file_o_close);
	free(buffer);
	return (0);
}
