#include "monty.h"

/* Global structure to store file and stack-related data */
bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - Entry point to the Monty code interpreter
 * @argc: Number of arguments passed to the program
 * @argv: Array of arguments (including the filename and file location)
 * Return: 0 on successful execution, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	/* Check if the correct number of arguments is provided */
	if (argc != 2)
	{
		fprintf(stderr, "USE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	/* Check if file opening is successful */
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Read and execute each line of the file */
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;

		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}

		free(content);
	}

	/* Free the allocated stack memory and close the file */
	f_free_stack(stack);
	fclose(file);

	return (0);
}
