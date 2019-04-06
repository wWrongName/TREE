//Структура описывается указателями на левый и правый потомок, значением и весом узла
//typedef struct NODE{
//	double  value;
//	int  weight;
//	struct NODE *left;
//	struct NODE *right;
//} NODE;

//Функция выделяет память для нового узла, присвает ему значение и создаёт для левого и правого потомков NULL указатели
//NODE *create_node(double val);

//Функция задаёт вес узла опираясь на данные потомков
//void count_weight(NODE *ptr); 

//Функция расчитывает разницу в весе поддеревьев
//int  difference(NODE *ptr);

//Функции балансировки узлов дерева (вызываются из функции twice_balance в зависимости от условий)
//NODE *left_to_right(NODE *top);
//NODE *right_to_left(NODE *top);

//Управляющая функция балансировки узлов
//NODE *twice_balanse(NODE *top);

//Функции добавления и удаления узлов
//NODE *insert(NODE *ptr, double val);
//NODE *n_remove(NODE *ptr, double val);

//Проверяет на дубликаты входные значения
//int search_for_twise(NODE *tree, double val);

//Функции балансировки при удалении элемента из дерева
//NODE *find_least(NODE *ptr);
//NODE *remove_least(NODE *top);
