#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "List.h"

/******************** LINKED LIST METHODS *****************/

// initialize the linked list
void initList(List* list) {
	list->head = NULL;
	list->tail = NULL;
}

/***********************************************************/
node* newNode(char* name, double value) {
	node* n = malloc(sizeof(node));
	strcpy(n->variable.name, name);
	n->variable.value = value;
	n->next = NULL;
	return n;
}
/***********************************************************/
double getValue(node* n) {
	if (n == NULL)
		return INT_MIN;
	return n->variable.value;
}
/***********************************************************/
char* getName(node* n) {
	if (n == NULL)
		return NULL;
	return n->variable.name;
}
/***********************************************************/
void setName(node* n, char* name) {
	strcpy(n->variable.name, name);
}
/***********************************************************/
// gets the number of nodes in the list
int getListSize(List* list) {
	node* traversal = list->head;

	if (traversal == NULL)
		return 0;

	int count = 0;

	while (traversal != NULL) {
		count++;
		traversal = traversal->next;
	}

	return count;
}
/***********************************************************/
/* checks if a given node exits in a given list
 * returns 1 if it exists
 * returns 0 if it doesn't
 */
int NodeExistsInList(List* list, node* n) {
	if (list->head == NULL || n == NULL)
		return 0;

	// traversal pointer
	node* trav = list->head;

	// loop the list looking for the node
	while (trav != NULL) {
		if (trav == n)
			return 1;
		trav = trav->next;
	}

	// node doesn't exist in list
	return 0;
}
/***********************************************************/
void addHead(List* list, char* name, double value) {
	node* node = newNode(name, value);
	node->next = list->head;
	list->head = node;

	// if the list was originally empty
	// then set the tail to point at the node just created
	if (list->tail == NULL) {
		list->tail = node;
	}
}
/***********************************************************/
void addTail(List* list, char* name, double value) {
	node* node = newNode(name, value);

	// special case: first node in list
	if (list->tail == NULL) {
		list->tail = node;
		list->head = node;
	} else {
		list->tail->next = node;
		list->tail = node;
	}
}
/***********************************************************/
void deleteHead(List* list) {
	// if list is empty or has one node
	if (list->tail == list->head) {
		// if not empty
		if (list->head != NULL)
			free(list->head);
		initList(list);
	} else {
		node* temp = list->head;
		list->head = list->head->next;
		free(temp);
	}

}
/***********************************************************/
void deleteTail(List* list) {
	// check if list is empty
	if (list->tail == NULL)
		return;

	// check if there is only one node in the list
	if (list->tail == list->head) {
		// only one node in the list
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}

	// else there are more than one node in the list
	// loop the list and keep a pointer on the node before the last
	node* prev;
	node* traversal = list->head;

	while (traversal != NULL) {
		prev = traversal;
		traversal = traversal->next;
	}
	// free the last node
	free(traversal);

	// update the tail
	list->tail = prev;

	// update the last node's pointer
	prev->next = NULL;
}
/***********************************************************/
// deletes a given node from a list
void deleteNode(List* list, node* n) {
	if (list->head == NULL)
		return;

	if (n == NULL)
		return;

	// check if node given exists in the list
	if (!NodeExistsInList(list, n))
		return;

	// check if there is only one node in the list
	if (list->tail == list->head) {
		free(list->head);
		list->head = list->tail = NULL;
		return;
	}

	// loop the list and keep a pointer on the node before the node to be deleted
	node* prev;
	node* traversal = list->head;

	while (traversal != n) {
		prev = traversal;
		traversal = traversal->next;
	}

	// update the "next" of the node before the node to be deleted
	prev->next = traversal->next;

	// update the tail if the node to be deleted was the last node
	if (traversal == list->tail)
		list->tail = prev;

	//update the head if the node to be deleted was the first node in the list
	if (traversal == list->head)
		list->head = traversal->next;

	// delete the node
	free(traversal);
}
/***********************************************************/
int isEmpty(List* list) {
	return list->head == NULL ? 1 : 0;
}
