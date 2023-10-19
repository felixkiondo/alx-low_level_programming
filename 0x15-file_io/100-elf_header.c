#include "main.h"

/**
 * display_error - Display an error message indicating that the file is not a valid ELF file.
 */
void display_error()
{
	fprintf(stderr, "Error: Not a valid ELF file.\n");
	exit(98);
}

/**
 * display_elf_header - Display the information contained in the ELF header at the start of an ELF file.
 * @f: The name of the ELF file.
 */
void display_elf_header(const char *f)
{
	int fd;
	Elf64_Ehdr header;

	fd = open(f, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	if (read(fd, &header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		display_error();
	}

	if (!(header.e_ident[EI_MAG0] == ELFMAG0 &&
	header.e_ident[EI_MAG1] == ELFMAG1 &&
	header.e_ident[EI_MAG2] == ELFMAG2 &&
	header.e_ident[EI_MAG3] == ELFMAG3))
	{
		display_error();
	}

	printf("Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	putchar('\n');

	printf("Class:   %s\n", header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("Data:    %s\n", header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big-endian" : "2's complement, little-endian");
	printf("Version: %d (current)\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type:    %d\n", header.e_type);
	printf("Entry point address: %lx\n", (unsigned long)header.e_entry);

	close(fd);
}

/**
 * main - Entry point of the program.
 * @c: Number of command line arguments.
 * @v: Array of command line arguments.
 *
 * Return: 0 if successful, 1 if incorrect usage.
 */
int main(int c, char *v[])
{
	if (c != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", v[0]);
		return 1;
	}

	display_elf_header(v[1]);

	return 0;
}
