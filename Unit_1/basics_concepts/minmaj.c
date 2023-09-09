#define _POSIX_C_SOURCE 200809L  // getline in POSIX.1-2008
#define _GNU_SOURCE

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

size_t getline(char **lineptr, size_t *n, FILE *stream) {
    char *bufptr = NULL;
    char *p = bufptr;
    size_t size;
    int c;

    if (lineptr == NULL) {
        return -1;
    }
    if (stream == NULL) {
        return -1;
    }
    if (n == NULL) {
        return -1;
    }
    bufptr = *lineptr;
    size = *n;

    c = fgetc(stream);
    if (c == EOF) {
        return -1;
    }
    if (bufptr == NULL) {
        bufptr = malloc(128);
        if (bufptr == NULL) {
            return -1;
        }
        size = 128;
    }
    p = bufptr;
    while(c != EOF) {
        if ((size_t)(p - bufptr) > (size - 1)) { // By casting the result of p - bufptr to size_t, you ensure that both sides of the comparison have the same signedness, and the warning should no longer appear.
            size = size + 128;
            bufptr = realloc(bufptr, size);
            if (bufptr == NULL) {
                return -1;
            }
        }
        *p++ = c;
        if (c == '\n') {
            break;
        }
        c = fgetc(stream);
    }

    *p++ = '\0';
    *lineptr = bufptr;
    *n = size;

    return p - bufptr - 1;
}

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
