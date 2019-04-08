#ifndef _TREE_
#define _TREE_

//Структура узла с указателями на левый и правый потомки, значением и весом
typedef struct NODE{
	double  value;
	int  weight;
	struct NODE *left;
	struct NODE *right;
} NODE;

//Проверяет входные значения на дубликаты
int search_for_twise(NODE *tree, double val);

//Удаляет дерево
void clear_tree(NODE *tree);

//Выделяет память для узла, присвает указателям на потомки NULL и присвает числовое значение переменной value
NODE *create_node   (double val);

//Считает вес узла, опираясь на вес потомков
void count_weight   (NODE *ptr);

//Находит разницу "в весе" между двумя поддеревьями
int  difference     (NODE *ptr);

//Функции балансировки дерева при вставке и после удаления элемента
NODE *left_to_right (NODE *top);
NODE *right_to_left (NODE *top);

//Управляющая функция балансировки(вызывает left_to_right и right_to_left в зависимости от условий)
NODE *twice_balanse (NODE *top);

//Функции балансировки при удалении элемента
NODE *find_least    (NODE *ptr);
NODE *remove_least  (NODE *top);

//Функции вставки и удаления узлов
NODE *insert        (NODE *ptr, double val);
NODE *n_remove      (NODE *ptr, double val);

//Выдают описания к ошибкам при попытке открытия файла
void error1();
void error2();

#endif
