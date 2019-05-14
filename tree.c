#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void help() {
	printf("\nINSTRUCTION\n");
	printf("Program have five available options:\n");
	printf("insert (inserts one number into the tree)\n");
	printf("remove (removes one number from the tree)\n");
	printf("read   (reads numbers from .txt)\n");
	printf("write  (writes tree into .txt in the form of a table)\n");
	printf("exit   (exit the program)\n\n");
	printf("> ");
}

void intro() {
	printf("Hello! This program implements a binary search tree.\n");
	printf("Now you can make the tree. For help type 'help'.\n\n");
	printf("> ");
}

NODE *clear_tree(NODE *tree) {
	if (tree->left != NULL)
		tree->left = clear_tree(tree->left);
	if (tree->right != NULL)
		tree->right = clear_tree(tree->right);
	free(tree);
	return NULL;
}

int search_for_twice(NODE *tree, double val) {
	NODE *tmp = tree;
	while (1) {
		if (tmp == NULL)
			return 0;
		if (tmp->value == val)
			return 1;
		if (val < tmp->value)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
}


NODE *create_node(double val) {
	NODE *node = (NODE*)malloc(sizeof(NODE));
	node->left = NULL;
	node->right = NULL;
	node->value = val;
	return node;
}

void count_weight(NODE *ptr) {
	unsigned int l_weight;
	unsigned int r_weight;

	l_weight = ptr->left  != NULL ? ptr->left->weight  : 0;
	r_weight = ptr->right != NULL ? ptr->right->weight : 0;
	ptr->weight = r_weight >= l_weight ? r_weight : l_weight;
	ptr->weight++;
}

int difference(NODE *top) {
	int lw, rw;
	lw = top->left  != NULL ? top->left->weight  : 0;
	rw = top->right != NULL ? top->right->weight : 0;
	return lw - rw;
}

NODE *find_least(NODE *top) {
	NODE *tmp = top;
	if (tmp == NULL) {
		return tmp;
	}
	while (1) {
		if (tmp->left != NULL)
			tmp = tmp->left;
		else
			return tmp;
	}
}

NODE *remove_least(NODE *top) {
	if (top->left != NULL)
		top->left = remove_least(top->left);
	else {
		NODE *tmp_right = top->right;
		free(top->right);
		return tmp_right;
	}
	return twice_balanse(top);
}

NODE *left_to_right(NODE *top) {
	NODE *left_branch = top->left;
	top->left = left_branch->right;
	left_branch->right = top;
	count_weight(left_branch);
	count_weight(top);
	return left_branch;
}

NODE *right_to_left(NODE *top) {
	NODE *right_branch = top->right;
	top->right = right_branch->left;
	right_branch->left = top;
	count_weight(right_branch);
	count_weight(top);
	return right_branch;
}

NODE *twice_balanse(NODE *top) {
	count_weight(top);
	if (difference(top) >= 2) {
		if (difference(top->left) < 0)
			top->left = right_to_left(top->left);
		return left_to_right(top);
	}
	if (difference(top) <= -2) {
		if (difference(top->right) > 0)
			top->right = left_to_right(top->right);
		return right_to_left(top);
	}
	return top;
}

NODE *insert_n(NODE *ptr, double val) {
	if (ptr == NULL) {
		ptr = create_node(val);
		ptr->value = val;
	}
	else if (val < ptr->value)
		ptr->left = insert_n(ptr->left, val);
	else 
		ptr->right = insert_n(ptr->right, val);
	return twice_balanse(ptr);
}

NODE *remove_n(NODE *ptr, double val) {
	if (ptr == NULL) {
		printf("Number does not exist\n");
		return ptr;
	}
	if (ptr->value == val) {
		printf("DELETED\n");
		NODE *left = ptr->left;
		NODE *right = ptr->right;
		free(ptr);
		if (right == NULL)
			return left;
		NODE *new_top = find_least(right);
		new_top->right = remove_least(right);
		new_top->left = left;
		return twice_balanse(new_top);
	}
	else if (val < ptr->value)
		ptr->left = remove_n(ptr->left, val);
	else
		ptr->right = remove_n(ptr->right, val);
	return twice_balanse(ptr);
}

void print_t(NODE *tree, unsigned int layer, FILE *output) {
	fprintf(output, "%d\t%lf\t\t%d\t%d\n", layer, tree->value, layer * 2 + 1, layer * 2 + 2);
	if (tree->left != NULL)
		print_t(tree->left, layer * 2 + 1, output);
	if (tree->right != NULL)
		print_t(tree->right, layer * 2 + 2, output);
}