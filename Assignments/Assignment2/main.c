#include <stdio.h>
#include "merger.h"

int main(int argc, char *argv[])
{
	// Pointer to argument
	char *dirname = argv[1];
	char *filename = argv[2];

	if (dirname == NULL || filename == NULL) {
		perror("Error: You must specify a foldername and a filename for the ouput");
		return 1;
	}
	
	// Merge files from the selected folder
	merge(dirname, filename);

	return 0;	
}
