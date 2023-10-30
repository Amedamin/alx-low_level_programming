#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "main.h"
#define SIZE 1024
#define  per (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
/**
 * main - Copy the content of one file to another.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code (97, 98, 99, or 100) on failure.
 *
 * Description:3-cp.c
 * This program takes two command-line arguments: the source file (file_from)
 * and the destination file (file_to). It copies the content of the source
 * file to the destination file while handling various error conditions.
 *
 * Error Codes:
 *  - 97: Incorrect usage. Should be "cp file_from file_to".
 *  - 98: Failed to read from the source file.
 *  - 99: Failed to write to the destination file.
 *  - 100: Failed to close a file descriptor.
 */

int main(int argc, char *argv[])
{const char *file_from = argv[1];
	const char *file_to = argv[2];
	int ptr_from, ptr_to;
	char buf[SIZE];
	ssize_t r, w;

	if (argc != 3)
	{ dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97); }
	ptr_from = open(file_from, O_RDONLY);
	r = read(ptr_from, buf, SIZE);
	ptr_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, per);

	if (ptr_from == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	do {
		if (r == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98); }
		w = write(ptr_to, buf, r);
		if (ptr_to == -1 || w == -1)
		{ dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99); }
		r = read(ptr_from, buf, SIZE);
		ptr_to = open(file_to, O_WRONLY | O_APPEND);
	} while (r > 0);

	if (close(ptr_from) == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ptr_from);
		exit(100); }
	if (close(ptr_to) == -1)
	{dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", ptr_to);
		exit(100); }
	return (0); }
