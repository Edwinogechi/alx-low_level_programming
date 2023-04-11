#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <elf.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - A function that checks if a file is an ELF file.
 * @e_ident: Pointer parameter to an array that contains the ELF magic numbers.
 *
 * Description: If the file is not an ELF file, or on error.
 */

void check_elf(unsigned char *e_ident)
{
	int i;

	/* Iterate over the first four bytes of e_ident checking if they match*/
	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 &&
		    e_ident[i] != 'E' &&
		    e_ident[i] != 'L' &&
		    e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - A function that prints the magic numbers of an ELF header.
 * @e_ident: Pointer parameter to an array that contains ELF magic numbers.
 *
 * Description: The given magic numbers be separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int j;

	/* First print the label for the ELF magic numbers */

	printf("  Magic:   ");

	/* Then Iterate over the array of magic numbers*/
	for (j = 0; j < EI_NIDENT; j++)
	{
		/*Print the present magic number as a two-digit hexadecimal number*/
		printf("%02x", e_ident[j]);

		/* Incase it is the last magic number, print a new line character */
		if (j == EI_NIDENT - 1)
			printf("\n");
		/*If not, print a space as a character to separate the magic numbers */
		else
			printf(" ");
	}
}


/**
 * print_class - A function that prints the class of an ELF header.
 * @e_ident: Pointer parameter to an array having the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	/* First, Print the ELF class label */
	printf("  Class:                             ");

	/* S-statement determining the ELF class by the value of the EI_CLASS byte */

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:

		/* Print "none" if the class is ELFCLASSNONE */

		printf("none\n");
		break;
	case ELFCLASS32:
		/* Print "ELF32" if the class is ELFCLASS32 */
		printf("ELF32\n");
		break;
	case ELFCLASS64:

		/* Print "ELF64" if the class is ELFCLASS64 */
		printf("ELF64\n");
		break;
	default:
		/* Print "<unknown: %x>" if none of these values results */
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - A function that prints the data of an ELF header.
 * @e_ident: Pointer parameter to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	/* Print the lable for encoding the ELF data */
	printf("  Data:                              ");

	/* S-statement determining data encoding based on the EI_DATA byte value */
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:

		/* Print "none" if the data encoding is ELFDATANONE */
		printf("none\n");
		break;
	case ELFDATA2LSB:

		/*Print "2's complete, little endian if the encode data is ELFDATA2LSB */
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:

		/*Print "2's complete, big endian if the encode data is ELFDATA2MSB */
		printf("2's complement, big endian\n");
		break;
	default:

		/* print "<unknown: %x>" with the value of the EI_DATA byte on default */
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * print_version - A function that prints the version of an ELF header.
 * @e_ident: Parameter pointer pointing to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - A function that prints the OS/ABI of an ELF header.
 * @e_ident: Parameter pointer pointing to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
 * print_abi - A function that prints the ABI version of an ELF header.
 * @e_ident: Pointer pointing to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - A function that prints the type of an ELF header.
 * @e_type: The ELF type parameter.
 * @e_ident: A pointer pointing to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


/**
 * print_entry - A function that prints the entry point of an ELF header.
 * @e_entry: The parameter address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - A function that closes an ELF file.
 * @elf: Parameter of the  file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * main - A function that displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: Parameter of the number of arguments supplied to the program.
 * @argv: An array of pointers pointing to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	/* Declare variables for ELF header,file descriptor,command line arguments*/
	Elf64_Ehdr *header;
	int op, rd;
	/* Try opening the specified file in the command line arguments */
	op = open(argv[1], O_RDONLY);
	if (op == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	/*Read the ELF file header from the given file and free memory if absent */
	rd = read(op, header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(header);
		close_elf(op);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	/* Check to ensure the file is a valid ELF file */
	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);
	free(header);
	close_elf(op);
	return (0);
}
