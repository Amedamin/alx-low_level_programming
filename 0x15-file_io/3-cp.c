#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void exit_with_error(const char *message, int exit_code) {
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

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
