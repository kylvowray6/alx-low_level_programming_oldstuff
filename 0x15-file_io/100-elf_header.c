#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * error_exit - Print error message and exit with status code 98.
 * @message: The error message to print.
 */
void error_exit(char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(98);
}

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Return: 0 on success, or appropriate error code on failure.
 */
int main(int argc, char *argv[])
{
    int fd;
    ssize_t bytes_read;
    Elf64_Ehdr elf_header;

    if (argc != 2)
        error_exit("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        error_exit("Error: Cannot read from file");

    bytes_read = read(fd, &elf_header, sizeof(elf_header));
    if (bytes_read != sizeof(elf_header))
        error_exit("Error: Cannot read from file");

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
        error_exit("Error: Not an ELF file");

    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%2.2x%c", elf_header.e_ident[i], i == EI_NIDENT - 1 ? '\n' : ' ');

    printf("  Class:                             ");
    switch (elf_header.e_ident[EI_CLASS])
    {
        case ELFCLASS32: printf("ELF32\n"); break;
        case ELFCLASS64: printf("ELF64\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Data:                              ");
    switch (elf_header.e_ident[EI_DATA])
    {
        case ELFDATA2LSB: printf("2's complement, little endian\n"); break;
        case ELFDATA2MSB: printf("2's complement, big endian\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Version:                           %d (current)\n", elf_header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header.e_ident[EI_OSABI])
    {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        default: printf("<unknown>\n"); break;
    }
    printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (elf_header.e_type)
    {
        case ET_NONE: printf("NONE (Unknown type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown>\n"); break;
    }

    printf("  Entry point address:               0x%lx\n", elf_header.e_entry);

    close(fd);
    return (0);
}
