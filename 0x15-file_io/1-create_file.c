#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * create_file - Create a file with specified name.
 *
 * @filename: The name of the file to be created.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 *         The created file has permissions: rw-------.
 * If the file already exists, it will be truncated .
 * If filename is NULL, return -1.
 *         If text_content is NULL, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int w, len = 0, ptr;

	if (filename == NULL)
		return (-1);

	ptr = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

	if (ptr == -1)
		return (-1);

	if (text_content != NULL)
	{		len = strlen(text_content);

		w = write(ptr, text_content, len);
	}

	if (w == -1)
		return (-1);

	close(ptr);

	return (1);
}
