#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 1024
/**
 * ex_error - It prints the error statement and executes exit.
 * @Mes: The error message to display.
 * @e_exit: The exit code to use when exiting the program.
 */
void ex_error(const char *Mes, int e_exit)
{
	dprintf(STDERR_FILENO, "Error: %s\n", Mes);
	exit(e_exit);
}

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

int main(int argc, char *argv[]) {
	// Check the number of arguments
	if (argc != 3) {
		exit_with_error("Usage: cp file_from file_to", 97);
	}

	char *file_from = argv[1];
	char *file_to = argv[2];

	// Open the source file
	int fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	// Open the destination file with truncation
	int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_to == -1) {
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	// Copy the content from source to destination
	char buffer[BUFFER_SIZE];
	ssize_t read_count, write_count;

	while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
		write_count = write(fd_to, buffer, read_count);
		if (write_count == -1) {
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}

	// Handle read error
	if (read_count == -1) {
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}

	// Close file descriptors
	if (close(fd_from) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}

	if (close(fd_to) == -1) {
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return 0;
}
