#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

// structure of a variable
typedef struct Variable {
	char* name;
	double value;
} Variable;

// node structure
typedef struct node {
	Variable variable;
	struct node* next;
} node;

// Linked List structure
typedef struct List {
	node* head;
	node* tail;
} List;
/*******************************************************/
/**
 * @brief initializes a list to start performing operations on it
 * @param list takes a pointer to the list to initialize it
 */
void initList(List* list);

/**
 * @brief adds a new variable to the head of a list of variables
 * @param list the pointer to the list to add the new variable/node to
 * @param name the pointer to the string containing the variable name
 * @param value the value of the variable
 */
void addHead(List* list, char* name, double value);

/**
 * @brief adds a new variable to the tail of a list of variables
 * @param list the pointer to the list to add the new variable/node to
 * @param name the pointer to the string containing the variable name
 * @param value the value of the variable
 */
void addTail(List* list, char* name, double value);

/**
 * @brief deletes the head/first node of a list
 * @param list the pointer to list where the head variable will be deleted
 */
void deleteHead(List* list);

/**
 * @brief deletes the tail/last node of a list
 * @param list the pointer to list where the head variable will be deleted
 */
void deleteTail(List* list);

/**
 * @brief returns 1 if the list is empty, 0 otherwise
 * @param list the pointer to the list
 */
int isEmpty(List* list);

/**
 * @brief creates a new node with the given vriable name and value
 * @param name the pointer to the string/array of chars containing the variable name
 * @param value the value of the variable
 */
node* newNode(char* name, double value);

/**
 * @brief returns a value of the variable pointed to by the given node
 * @param n the pointer to node
 * @return returns the value of the variable
 * @return returns INT_MIN if the node pointer is NULL
 */
double getValue(node* n);

/**
 * @brief sets the value of the pointer pointed to by n with
 * the given value.
 *
 * @param n the pointer to the node representing the variable
 * @param value the value of the variable that will be set
 */
void setValue(node* n, double value);

/**
 * @brief returns a pointer to the name of the variable
 * pointed to by the given node.
 *
 * @param n the pointer to the node representing the variable
 * @return returns the pointer to the string holding
 * the name of the variable
 *
 * @return returns NULL if the node pointer is NULL
 */
char* getName(node* n);

/**
 * @brief sets the name of the variable pointed to by the given parameter n
 * to the string pointed to by the given parameter name
 * @param n the pointer to node representing the variable
 */
void setName(node* n, char* name);

/**
 * @brief returns the number of nodes in the list
 * @param list the pointer to the list
 * @return returns an integer representing the number of nodes in the list
 * @return returns 0 if the list pointer is NULL
 */
int getListSize(List* list);

/**
 * @brief checks if a given node exists in a given list
 * @param list the pointer to the list
 * @param n the pointer to the node to look for (to check if
 * it exists in the list)
 * @return returns 1 if the node exists in the list
 * @return returns 0 if the node does not exist in the list
 */
int NodeExistsInList(List* list, node* n);

/**
 * @brief deletes a node from the list, whether this
 * node is at the head, tail or middle of the list
 *
 * @param list the pointer to the list
 */
void deleteNode(List* list, node* n);

#endif // LIST_H_INCLUDED
