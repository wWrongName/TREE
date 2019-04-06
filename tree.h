#ifndef _TREE_
#define _TREE_


typedef struct NODE{
	double  value;
	int  weight;
	struct NODE *left;
	struct NODE *right;
} NODE;

void count_weight   (NODE *ptr);
int  difference     (NODE *ptr);
NODE *remove_least  (NODE *top);
NODE *find_least    (NODE *ptr);
NODE *left_to_right (NODE *top);
NODE *right_to_left (NODE *top);
NODE *twice_balanse (NODE *top);
NODE *insert        (NODE *ptr, double val);
NODE *n_remove      (NODE *ptr, double val);
int search_for_twise(NODE *tree, double val);
NODE *create_node   (double val);
void error1();
void error2();

#endif _TREE_
