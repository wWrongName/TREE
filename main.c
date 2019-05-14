#include <stdio.h>
#include <string.h>
#include "tree.h"


int main(int argc, char **argv)
{
	NODE *tree = NULL;
	char file_name[1000];
	char str[7];
	char *arg;
	double value;

	intro();
	scanf("%s", &str);
	arg = _strdup(str);

	while (strcmp(arg, "exit")) {
		if(!strcmp(arg, "help"))
			help();

		else if(!strcmp(arg, "insert")) {
			printf("input number: ");
			scanf("%lf", &value);
			if (!search_for_twice(tree, value))
				tree = insert_n(tree, value);
			printf("\n> ");
		}

		else if(!strcmp(arg, "remove")){
			printf("input number: ");
			scanf("%lf", &value);
			tree = remove_n(tree, value);
			printf("\n> ");
		}

		else if(!strcmp(arg, "read")) {
			printf("input file: ");
			scanf("%s", &file_name);
			FILE *input = fopen(file_name, "r");
			if (input == NULL) 
				printf("File was not found. Plaease, check the file path.\n");
			else {
				while (fscanf(input, "%lf", &value) != EOF) {
					if (!search_for_twice(tree, value))
						tree = insert_n(tree, value);
				}
				fclose(input);
				printf("Data was read successfully!\n\n");
			}
				printf("> ");
		}

		else if(!strcmp(arg, "write")) {
			printf("output file: ");
			scanf("%s", &file_name);
			FILE *output = fopen(file_name, "w");
			if (output == NULL) 
				printf("File was not created. Please check a file path or available memory\n\n");
			else {
				fprintf(output, "POS\tVAL\t\t\tL\tR\n");
				print_t(tree, 0, output);
				fclose(output);
				printf("Data was written successfully!\n\n");
			}
			printf("> ");
		}

		else {
			printf("Incorrect input. Type 'help' to get the list of available options\n\n");
			printf("> ");
		}
		scanf("%s", &str);
		arg = _strdup(str);
	}

	if(tree != NULL)
		tree = clear_tree(tree);

	return 0;
}