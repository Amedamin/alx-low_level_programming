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

int main(int argc, char *argv[])
{const char *file_from;
	const char *file_to;
	int ptr_from, ptr_to;
	char buf[SIZE];
	ssize_t r, w;

	if (argc != 3)
		ex_error("Usage: cp file_from file_to", 97);
	file_from = argv[1];
	file_to = argv[2];
	ptr_from = open(file_from, O_RDONLY);

	if (ptr_from == -1)
		ex_error("Can't read from file", 98);
	ptr_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (ptr_to == -1)
	{
		close(ptr_from);
		ex_error("Can't write to file", 99); }
	while ((r = read(ptr_from, buf, SIZE)) > 0)
	{
		w = write(ptr_to, buf, r);
		if (w != r || w == -1)
		{
			close(ptr_from);
			close(ptr_to);
			ex_error("Can't write to file", 99);
		}}

	if (r == -1)
	{
		close(ptr_from);
		close(ptr_to);
		ex_error("Can't read from file", 98);
	}

	if (close(ptr_from) == -1 || close(ptr_to) == -1)
		ex_error("Can't close ptr", 100);
	return (0);
}
