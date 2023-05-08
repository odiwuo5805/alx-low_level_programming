#include "main.h"
#include <stdlib.h>
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *  Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t p, y, w;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	p = open(filename, O_RDONLY);
	y = read(p, buffer, letters);
	w = write(STDOUT_FILENO, buffer, y);

	if (p == -1 || y == -1 || w == -1 || w != y)
	{
		free(buffer);
		return (0);
	}

	free(buffer);
	close(p);

	return (w);
}

