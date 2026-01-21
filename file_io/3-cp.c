#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int open_from(char *file);
int open_to(char *file);
void copy_file(int fd_from, int fd_to, char *file_from, char *file_to);
void close_fd(int fd);

/**
 * main - copies content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, exits with 97,98,99,100 on errors
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_from(av[1]);
	fd_to = open_to(av[2]);
	copy_file(fd_from, fd_to, av[1], av[2]);
	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/* --- helper functions below --- */

int open_from(char *file)
{
	int fd = open(file, O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
	}
	return (fd);
}

int open_to(char *file)
{
	int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}
	return (fd);
}

void copy_file(int fd_from, int fd_to, char *file_from, char *file_to)
{
	ssize_t n_read, n_written;
	char buffer[1024];

	while ((n_read = read(fd_from, buffer, 1024)) > 0)
	{
		n_written = write(fd_to, buffer, n_read);
		if (n_written != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
