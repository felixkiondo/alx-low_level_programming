#include "main.h"

/**
 * print_elf - Prints the ELF header information
 * @header: Pointer to the ELF header structure
 */
void print_elf(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:  ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}

	printf("\n");
	printf("Class:  %d\n", header->e_ident[EI_CLASS]);
	printf("Data:  %d\n", header->e_ident[EI_DATA]);
	printf("Version:  %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version:  %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:  %d\n", header->e_type);
	printf("Entry point address:  %lx\n", header->e_entry);
}
/**
 * is_elf - Checks if the file is an ELF file
 * @header: Pointer to the ELF header structure
 * Return: int Status code
 */
int is_elf(Elf64_Ehdr *header)
{
	if (header->e_ident[EI_MAG0] != ELFMAG0 ||
	header->e_ident[EI_MAG1] != ELFMAG1 ||
	header->e_ident[EI_MAG2] != ELFMAG2 ||
	header->e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Not an ELF file\n");
		return (98);
	}

	return (0);
}
/**
 * main - Entry point
 * @c: Argument count
 * @v: Argument vector
 * Return: int Status code
 */
int main(int c, char **v)
{
	int f;
	Elf64_Ehdr header;

	if (c != 2)
	{
		fprintf(stderr, "Usage: elf_header elf_filename\n");
		return (98);
	}

	f = open(v[1], O_RDONLY);
	if (f == -1)
	{
		perror("Error opening file");
		fprintf(stderr, "Filename: %s\n", v[1]);
		return (98);
	}

	if (read(f, &header, sizeof(header)) != sizeof(header))
	{
		perror("Error reading ELF header");
		fprintf(stderr, "Filename: %s\n", v[1]);
		close(f);
		return (98);
	}

	if (is_elf(&header))
	{
		fprintf(stderr, "Not an ELF file: %s\n", v[1]);
		close(f);
		return (98);
	}
	print_elf(&header);
	if (close(f) == -1)
	{
		perror("Error closing file");
		fprintf(stderr, "Filename: %s\n", v[1]);
		return (98);
	}

	return (0);
}
