#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
 * read_textfile - Read text file and print to STDOUT.
 *
 * @filename: The text file being read.
 * @letters: The number of letters to be read.
 *
 * Return: The actual number of bytes read and printed (w).
 *         0 when the function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t total_bytes = 0;
	char *s = malloc(sizeof(char) * letters);
	size_t r;
	size_t w;
	FILE *ptr;

	if (filename == NULL)
		return (0);

	ptr = fopen(filename, "r");
	if (ptr == NULL)
		return (0);

	while (letters > 0)
	{
		size_t num = letters;

		r = fread(s, 1, num, ptr);

		if (r == 0)
			break;

		w = write(STDOUT_FILENO, s, r);

		if (r != w)
			break;
		total_bytes += w;

		letters -= w;
	}
	fclose(ptr);
	return (total_bytes);
}
