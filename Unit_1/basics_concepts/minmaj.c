#define _POSIX_C_SOURCE 200809L  // getline in POSIX.1-2008

/* à compléter: entêtes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LEN 64
/*
 * readline() reads an entire line from stream and stores at most one less than
 * size characters into the buffer pointed to by buffer.
 * A terminating null byte ('\0') is stored after the last character in the
 * buffer.
 *
 * On success, readline() returns the number of characters read, excluding the
 * terminating null byte ('\0').
 *
 * The function returns -1 on failure to read a line (including end-of-file
 * condition).
 */
static ssize_t readline(char *buffer, size_t size, FILE *stream)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	ssize_t ncopied = -1;

	nread = getline(&line, &len, stream);
	if (nread != -1) {
		// copy at most size - 1 bytes
		ncopied = nread < (ssize_t)size - 1 ? nread : (ssize_t)size - 1;
		memcpy(buffer, line, ncopied);
		// terminating null byte
		buffer[size] = '\0';
	}
	free(line);

	return ncopied;
}

int main(void)
{
	/* à compléter: corps de main */


	// variables
	int lower = 0, upper = 0, other = 0;


	printf("Entrez une chaine quelconque : ");
	char buffer[BUFFER_LEN];
	ssize_t nread;
	nread = readline(buffer, BUFFER_LEN, stdin);

	//printf("%d\n\n", nread); to count how many character there is in the line.

	for (int i = 0; i < nread; i++)
	{
		if (buffer[i] >= 'a' && buffer[i] <= 'z') 
		{
			lower++;
		}
		else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
		{
			upper++;
		}
		else
		{
			other++;
		}
		
	}

	printf("lower : %d\n upper : %d\n other: %d\n", lower, upper, other);
	

	return EXIT_SUCCESS;
}
