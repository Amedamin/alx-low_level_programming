#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
void close_e(int elf);
void check_e(unsigned char *e_ident);
void print_(unsigned int type, unsigned char *e);
/**
 * close_e - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_e(int elf)
{
	if (close(elf) == -1)
		exit(98);
}
/**
 * check_e - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_e(unsigned char *e_ident)
{
	int x;

	for (x = 0; x < 4; x++)
	{
		if (e_ident[x] != 127 &&
				e_ident[x] != 'E' &&
				e_ident[x] != 'L' &&
				e_ident[x] != 'F')

		{
			dprintf(STDERR_FILENO, "Not an ELF file\n");
			exit(98);
		}
	}
}


/**
 * print_ - Prints the type of an ELF header.
 * @type: The ELF type.
 * @e: A pointer to an array containing the ELF class.
 */
void print_(unsigned int type, unsigned char *e)
{
	if (e[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf(" Type: ");

	switch (type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
	}
}
/**
 * main - Displays the information contained in the
 * ELF der at the start of an ELF file.
 * @ac: The number of arguments supplied to the program.
 * @av: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int ac, char **av)
{
	Elf64_Ehdr *der;
	int op, re;
	(void)re;
	(void)ac;

	op = open(av[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	der = malloc(sizeof(Elf64_Ehdr));
	re = read(op, der, sizeof(Elf64_Ehdr));

	check_e(der->e_ident);
	printf("ELF Header:\n");
	print_(der->e_type, der->e_ident);

	free(der);
	close_e(op);
	return (0);
}
