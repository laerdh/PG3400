#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "merger.h"

// Template: Files with 30x30 bytes
#define LIMIT 30

static int init();
static void clean();

void merge(char *dirname, const char *filename);
static void readFile();
static void readDir();
static void print();

static char **data;
static int rows = -1;
static int cols = -1;
static int row_pos;
static int col_pos;

void merge(char *dirname, const char *filename)
{
	if (dirname == NULL || strlen(dirname) < 1) {
		perror("Error: Please provide a directory name");
		exit(1);
	}

	if (filename == NULL || strlen(filename) < 1) {
		perror("Error: Please provide a output filename");
		exit(1);
	}
	
	// Gather filenames, rows and columns
	readDir(dirname);

	// Remove '/' from dirname if exist
	if (dirname[(strlen(dirname)-1)] == '/') {
		dirname[strlen(dirname)-1] = '\0';
	}
	
	// Initialize 2D-array based on rows/columns
	if (init() != 0) {
		exit(1);
	}

	// Using number of rows and cols
	// to open the files in the right order
	// example: i = 0, j = 0, dirname = "mickey" -> part_0_0_mickey.txt
	// Next iteration: part_1_9_mickey.txt and so on
	printf("> Started merging %s!\n", dirname); 
	char *tempfile;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int size = asprintf(&tempfile, "%s/part_%d_%d_%s.txt", dirname, j, i, dirname);
			if (size == -1) {
				perror("Error: Memory is full");
				return;
			}
	
			readFile(tempfile);			
			free(tempfile);
			
			// Set next column position
			col_pos += LIMIT;
		}

		// Set next row and first column
		row_pos += LIMIT;
		col_pos = 0;
	}
	
	// Print ascii to file
	print(filename);
	
	// Free up memory
	clean();
	printf("> Done merging %s! See %s\n", dirname, filename);
}

static int init()
{
	data = malloc((LIMIT*rows)*sizeof(char*));

	if (data == NULL) {
		perror("Error: Failed to allocate memory");
		return 1;
	}

	for (int i = 0; i < LIMIT*rows; i++) {
		data[i] = malloc((LIMIT*cols)*sizeof(char));

		if (data[i] == NULL) {
			perror("Error: Failed to allocate memory");
			return 1;
		}
	}
	
	return 0;
}

static void clean()
{
	for (int i = 0; i < LIMIT*rows; i++) {
		free(data[i]);
	}
	free(data);
}

static void readDir(const char *dirname)
{
	DIR *dir;
	struct dirent *in_file;

	if (NULL == (dir = opendir(dirname))) {
		perror("Error: Couldn't find directory");
		exit(1);
	}

	while ((in_file = readdir(dir)))
	{
		if (!strcmp(in_file->d_name, ".") || !strcmp(in_file->d_name, "..")) {
			continue;
		}
	
		int x = atoi(&in_file->d_name[5]);
		int y = atoi(&in_file->d_name[7]);

		if(x > cols) {
			cols++;
		}
		
		if (y > rows) {
			rows++;
		}
	}

	free(dir);

	// Add 1 due to 0-index
	rows++;
	cols++;	
	printf("> Read %d rows and %d columns\n", rows, cols);
}

static void readFile(const char *filename)
{
	FILE *file = fopen(filename, "r");
	char buffer[1];

	if (file == NULL) {
		perror("Error: File not found");
		return;
	}

	for (int i = 0; i < LIMIT; i++) {
		for (int j = 0; j < LIMIT; j++) {
			if (fread(buffer, sizeof(char), 1, file) == 0) {
				break;
			}
			strncpy(&data[row_pos+i][col_pos+j], buffer, sizeof(char));
		}
	}

	fclose(file);
}

void print(const char *filename)
{
	FILE *file = fopen(filename, "w");

	if (file == NULL) {
		perror("Error: Couldn't create file");
		return;
	}

	for (int i = 0; i < (LIMIT*rows); i++) {
		for (int j = 0; j < (LIMIT*cols); j++) {
			fprintf(file, "%c", data[i][j]);
		}
		fprintf(file, "\n");
	}

	fclose(file);	
}

