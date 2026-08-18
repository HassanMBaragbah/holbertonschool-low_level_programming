#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_osabi_and_abi(unsigned char *e);
void check_and_print_ident(unsigned char *e);
void print_type_and_entry(unsigned int e_type,
			  unsigned long int e_entry,
			  unsigned char *e);
void close_elf(int elf);

/**
 * print_osabi_and_abi - Prints OS/ABI and ABI version.
 * @e: Pointer to ELF magic numbers array.
 */
void print_osabi_and_abi(unsigned char *e)
{
	printf("  OS/ABI:                            ");
	switch (e[EI_OSABI])
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
		printf("<unknown: %x>\n", e[EI_OSABI]);
	}
	printf("  ABI Version:                       %d\n", e[EI_ABIVERSION]);
}

/**
 * check_and_print_ident - Checks if file is ELF and prints main header info.
 * @e: Pointer to ELF magic numbers array.
 */
void check_and_print_ident(unsigned char *e)
{
	int i;

	if (e[EI_MAG0] != 127 || e[EI_MAG1] != 'E' ||
	    e[EI_MAG2] != 'L' || e[EI_MAG3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e[i], i == EI_NIDENT - 1 ? "\n" : " ");

	printf("  Class:                             ");
	if (e[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (e[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", e[EI_CLASS]);

	printf("  Data:                              ");
	if (e[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (e[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", e[EI_DATA]);

	printf("  Version:                           %d%s",
	       e[EI_VERSION], e[EI_VERSION] == EV_CURRENT ? " (current)\n" : "\n");

	print_osabi_and_abi(e);
}

/**
 * print_type_and_entry - Prints type and entry point address.
 * @e_type: ELF type.
 * @e_entry: ELF entry point address.
 * @e: Pointer to ELF magic numbers array.
 */
void print_type_and_entry(unsigned int e_type,
			  unsigned long int e_entry,
			  unsigned char *e)
{
	if (e[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	if (e_type == ET_NONE)
		printf("NONE (None)\n");
	else if (e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", e_type);

	printf("  Entry point address:               ");
	if (e[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file descriptor.
 * @elf: File descriptor.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays ELF header info.
 * @argc: Arguments count.
 * @argv: Arguments array.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd, r;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	r = read(fd, &header, sizeof(header));
	if (r == -1 || r < (ssize_t)sizeof(header.e_ident))
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Cannot read header\n");
		exit(98);
	}

	check_and_print_ident(header.e_ident);
	print_type_and_entry(header.e_type, header.e_entry, header.e_ident);

	close_elf(fd);
	return (0);
}