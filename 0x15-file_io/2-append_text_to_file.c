#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * append_text_to_file - Append text to the end of a file.
 *
 * @filename: The name of the file to which text will be appended.
 * @text_content: The text content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int m, lenght = 0, l;

	if (filename == NULL)
		return (-1);

	l = open(filename, O_WRONLY | O_APPEND);

	if (l == -1)
		return (-1);

	if (text_content != NULL)
	{  lenght = strlen(text_content);

		m = write(l, text_content, lenght);
	}

	if (m == -1)
		return (-1);

	close(l);

	return (1);
}
