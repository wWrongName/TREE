#include "pch.h"
#include <stdio.h>
#include <string.h>
#include "tree.h"


int main(int argc, char *argv[])
{
	double val;
	const char* txt = ".txt";

	if (argc != 3) {
		error1();
		return 1;
	}
	if (strcmp(argv[1], "-i")) {
		error1();
		return 1;
	}
	if (NULL == strstr(argv[2], txt)) {
		error2();
		return 1;
	}
	
	FILE* input = fopen(argv[2], "r");
	if (input == NULL) {
		printf("ERROR: Input file (");
		printf(argv[2]);
		printf(") is not found\n");
		return 1;
	}
	NODE *tree = NULL;

	while (fscanf(input, "%lf", &val) != EOF) {
		if (!search_for_twise(tree, val))
			tree = insert(tree, val);
	}
	
	double temp;
	printf("Input a number to remove: ");
	scanf("%lf", &temp);
	tree = n_remove(tree, temp);
	free(tree);
	fclose(input);
	return 0;
}
