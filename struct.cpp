#include <stdio.h>
#include <stdlib.h>

struct point {
	int x;
	int y;
	struct point* next;
};

//1. Добавление элемента в «голову» 1.
struct point* addToHead(struct point** p, int x1, int y1) {
	struct point* ptrIx = (struct point*)malloc(sizeof(struct point));
	if (ptrIx) {
		ptrIx->x = x1;
		ptrIx->y = y1;
		ptrIx->next = NULL;
		if (*p == NULL)
		{
			*p = ptrIx;
		}
		else
		{
			ptrIx->next = *p;
			*p = ptrIx;
		}
		return *p;
	}
	return NULL;
}
//2. Добавление элемента в «хвост»
struct point* addToTail(struct point** p, int x1, int y1) {
	if (*p) {
		struct point* ptrIx = (struct point*)malloc(sizeof(struct point));
		if (ptrIx) {
			ptrIx->x = x1;
			ptrIx->y = y1;
			ptrIx->next = NULL;
			if (*p == NULL) {
				*p = ptrIx;
			}
			else {
				struct point* current = *p;
				while (current->next != NULL) {
					current = current->next;
				}
				current->next = ptrIx;
				return ptrIx;
			}
		}
		return NULL;
	}
	return NULL;
}
//3. Добавление элемента после заданного элемента
void AddAfter(struct point** p, int x1, int y1, int X, int Y) {
	if (p) {
		struct point* new_p = (struct point*)malloc(sizeof(struct point));  // Создаем новый элемент
		if (new_p == NULL) {
			printf("Memory error!!!\n");
			return;
		}
		else {
			new_p->x = X;
			new_p->y = Y;
			new_p->next = NULL;
		}
		if (*p) {

			if ((*p)->x == X && (*p)->y == Y) {
				addToHead(p, X, Y);  // Добавляем в голову, если ключ совпадает с головой
				return;
			}

			struct point* current = *p;
			struct point* previous = NULL;
			while (current->next != NULL && (current->x != x1 || current->y != y1)) {
				current = current->next;
				previous = current;
			}
			if (current->next == NULL) {  // Элемент с ключом не найден
				previous->next = new_p;
			}
			else {
				new_p->next = current->next;
				current->next = new_p;
			}	
		}
		else {
			*p = new_p;
		}
	}
	else {
		printf("Incorrect PTR!!!\n");
	}
}
//4. Добавление перед заданным элементом
void AddBefore(struct point** p, int x1, int y1, int X, int Y) {
	if (p) {
		struct point* new_p = (struct point*)malloc(sizeof(struct point));  // Создаем новый элемент
		if (new_p == NULL) {
			printf("Memory error!!!\n");
			return;
		}
		else {
			new_p->x = X;
			new_p->y = Y;
			new_p->next = NULL;
		}
		if (*p) {

			if ((*p)->x == X && (*p)->y == Y) {
				addToHead(p, X, Y);  // Добавляем в голову, если ключ совпадает с головой
				return;
			}

			struct point* current = *p;
			while (current->next != NULL && ((current->next) ->x != x1 && (current->next)->y != y1))
			{
				current = current->next;
			}

			if (current->next == NULL) {  // Элемент с ключом не найден
				printf("Point is not found!!!\n");
				return;
			}
			new_p->next = current->next;
			current->next = new_p;
		}
		else {
			*p = new_p;
		}
	}
	else {
		printf("Incorrect PTR!!!\n");
	}
}
//5. Удаление «головы»
void DelFromHead(struct point** p) { //двойной указатель передаёт адрес самого указателя
	if (*p) {
		struct point* ptrIx = *p;
		*p = (*p)->next;
		free(ptrIx);
		ptrIx = NULL;
	}
	else {
		printf("The list is NULL!!!\n");
		return;
	}
}
//6. Удаление «хвоста»
void DelFromTail(struct point** p) {
	if (p) {
		if (*p == NULL) {
			printf("the list is NULL!!!\n");
			return;
		}
		if ((*p)->next == NULL) {
			free(*p);
			*p = NULL;
			return;
		}
		struct point* current = *p;
		while ((current->next != NULL) && (current->next->next != NULL)) {
			current = current->next;
		}

		free(current->next);
		current->next = NULL;
	}
	else {
		printf("Incorrect PTR!!!\n");
	}
}
//7. Удаление элемента после заданным элементом
void DelAfter(struct point** p, int X, int Y) {
	if (p) {
		if (*p == NULL || (*p)->next == NULL) {
			printf("The list is NULL or one point!!!\n");
			return;
		}
		struct point* current = *p;
		struct point* ptrIx = NULL;
		while (current && (current->x != X || current->y != Y)) {
			current = current->next;
			ptrIx = current;
		}
		if (current->next == NULL) {
			printf("Point is not found!!!\n");
			return;
		}
		if (ptrIx == NULL) {
			struct point* tmp = *p;
			*p = (*p)->next;
			free(tmp);
		}
		else {
			struct point* tmp = ptrIx->next;
			ptrIx->next = current->next->next;
			free(tmp);
		}
	}
	else {
		printf("Incorrect PTR!!!\n");
	}
}
//8. Удаление элемента перед заданного элемента
void DelBefore(struct point** p, int X, int Y) {
	if (p) {
		if (*p == NULL) {
			printf("The list is NULL!\n");
			return;
		}
		struct point* current = *p;
		struct point* ptrIx = NULL;
		while (current && (current->x != X || current->y != Y)) {
			ptrIx = current;
			current = current->next;
		}
		
		if (current == NULL) {
			printf("Point is not found!!!\n");
			return;
		}
		struct point* tmp = *p;
		while (tmp && (tmp->next != ptrIx)) {
			tmp = tmp->next;
		}
		if (tmp != NULL && ptrIx != NULL) {
			ptrIx = tmp->next;
			tmp->next = ptrIx->next;
			free(ptrIx);
			ptrIx = NULL;
		}
	}
	else {
		printf("Incorrect PTR!!!\n");
	}
}
//упорядочивает список по возрастанию по координате X.
void sort(struct point** p) {
	if (*p == NULL || (*p)->next == NULL) {
		printf("the list is NULL or one point!!!\n");
		return;
	}
	int sw;
	struct point* ptrTx1;
	struct point* ptrIx2 = NULL;
	do {
		sw = 0;
		ptrTx1 = *p;
		while (ptrTx1->next != ptrIx2)
		{
			if ((ptrTx1->x) > (ptrTx1->next->x)) {
				int tmp1 = ptrTx1->x;
				int tmp2 = ptrTx1->y;
				ptrTx1->x = ptrTx1->next->x;
				ptrTx1->y = ptrTx1->next->y;
				ptrTx1->next->x = tmp1;
				ptrTx1->next->y = tmp2;
				sw = 1;
			}
			ptrTx1 = ptrTx1->next;
		}
		ptrIx2 = ptrTx1;
	} while (sw);
}
//10.Поиск элемента в списке
void SearchPoint(struct point** p, int X, int Y) {
	if (*p == NULL) {
		printf("The list is NULL!\n");
		return;
	}
	struct point* current = *p;
	int position = 0;
	while (current != NULL){		
		if (current->x == X || current->y == Y) {
			printf("Point (%d, %d) is find in position: %d.\n", X, Y, position);
			return;
		}
		current = current->next;
		position++;
	}
	printf("Point is not found!!!\n");
}

void printList(struct point* list) {
	if (list) {
		struct point* current = list;
		while (current) {
			printf("(%d, %d) -> ", current->x, current->y);
			current = current->next;
		}
		printf("NULL\n");
	}
	else {
		printf("Don`t print!!!\n");
	}
}

int main() {
	struct point* head = NULL;
	struct point* ptrIx = NULL, *Tail = NULL;
	addToHead(&head, 0, 0);
	addToHead(&head, 1, 1);
	addToHead(&head, 2, 2);
	addToHead(&head, 36, 2);
	addToHead(&head, 7, 215);
	addToHead(&head, 14, 6);
	addToHead(&head, 9, 3);
	addToHead(&head, 3, 3);
	addToHead(&head, 32, 7);
	addToHead(&head, 2, 2);
	addToHead(&head, 3, 3);
	addToHead(&head, 4, 4);
	addToHead(&head, 5, 5);
	printList(head);

	DelFromHead(&head);
	printList(head);

	addToTail(&head, 63, 15);
	printList(head);

	AddAfter(&head, 3, 3, 2, 4);
	printList(head);

	AddBefore(&head, 0, 0, 6, 5);
	printList(head);

	DelFromTail(&head);
	printList(head);

	DelAfter(&head, 1, 1);
	printList(head);

	DelBefore(&head, 2, 2);
	printList(head);

	SearchPoint(&head, 1, 1);
	sort(&head);
	printList(head);
	
	return 0;
}