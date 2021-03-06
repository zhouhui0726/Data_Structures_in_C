/*A structure that represents an individual node that will 
act as a link within the singly linked list. Void * data allows
this singly linked list to be of any type.*/
typedef struct Node
{
	struct Node * next; 
	void * data;
} Node;

/*The actua linked list structure which will keep reference
to the hed and tail of the list.*/
typedef struct DLinkedList 
{
	Node * head; 
	Node * currentNode;
	size_t listSize; 
} LinkedList;


/*Assumed that user passes an allocated LinkedList struct*/
void initializeList(LinkedList * list);
/*Returns the current size of the LinkedList*/
size_t listSize(LinkedList * list);
/*Adds a node with specified data to the front of LinkedList*/
void addFrontList(void * data , LinkedList * list);
/*Removes a node from the front of the list and data's memory is users responsibility to free*/
void removeFrontList(LinkedList * list);
/*Returns a void pointer to the value stored in node pointed 
to by Head of the linkedList*/
void* getHeadList(LinkedList * list);
/*Returns a void pointer to the values stored in node pointed to by Tail of 
DLinkedList*/
//void* getTailList(DLinkedList * list);
/*Adds a node with specified data to back of DLinkedList*/
//void addBackList(void * data , DLinkedList * list);
/*Removes a node from the back of the list and automatically frees data from node*/
//void removeBackList(DLinkedList * list);
/*Removes a node from the back of the list and data's memory is users responsibility to free*/
void * next(LinkedList * list);
/*Searches the DLinkedList lookng for specified element and returns that element if found ... user must pass a compare function that fits declation provided*/
void * findData( int (*compare)(void * a, void * b), void * data, LinkedList * list);
/*Removes all the nodes from the DLinkedList the data memory within each node must be taken care of by the user*/
void removeAll(LinkedList * list);
/*Prints the DLinkedList*/
void printList(LinkedList* List, void (*printFunc)(void* data));

