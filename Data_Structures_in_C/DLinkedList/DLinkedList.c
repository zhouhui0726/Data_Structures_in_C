#include <stdlib.h>
#include <stdio.h>
#include "DLinkedList.h"

/*Assumed that user passes an allocated DLinkedList struct*/
void initializeList(DLinkedList * list)
{
	list->currentNode = NULL;
	list->head = NULL;	
	list->tail = NULL;

	list->listSize = 0; 		
}

size_t listSize(DLinkedList * list)
{
	return list->listSize;
}
void addFrontList(void * data , DLinkedList * list)
{
	//Check if list is empty
	if(list->listSize == 0)
	{
		list->head = (Node*) malloc(sizeof(Node));
	
		list->tail = list->head;
		list->currentNode = list->head;
		list->tail->next = NULL;

		list->head->data = data;
	}
	else 
	{
		list->head->prev = (Node*) malloc(sizeof(Node));

		list->head->prev->next = list->head;
		list->head = list->head->prev;

		list->head->data = data;	
	}

	list->listSize++;
	list->head->prev = NULL;
}

void removeFrontList(DLinkedList * list)
{

	if(list->listSize == 0)
	{
		printf("List is empty nothing to remove.\n");
	}
	else
	{
		Node * tempNode = list->head; 

		if(list->listSize == 1)
		{
			list->head = list->tail = list->currentNode = NULL;
		}
		else
		{
			if(tempNode == list->currentNode)
			{
				list->currentNode = list->currentNode->next; 
			}
			
			list->head = list->head->next;
			list->head->prev = NULL;
		}
	
		--(list->listSize);

		free(tempNode); 
	}

}

void* getHeadList(DLinkedList * list)
{
	list->currentNode = list->head;
	if(list->currentNode)
	{
		return list->head->data;
	}
	
	return	NULL; 
}

void* getTailList(DLinkedList * list)
{
	list->currentNode = list->tail;

	if(list->currentNode)
	{
		return list->tail->data;
	}

	return NULL;
}

void addBackList(void * data , DLinkedList * list)
{
	//Check if list is empty
	if(list->listSize == 0)
	{
		list->head = (Node*) malloc(sizeof(Node));
	
		list->tail = list->head;
		list->currentNode = list->head;
		list->head->prev = NULL;

		list->head->data = data;
	}
	else 
	{
		list->tail->next = (Node*) malloc(sizeof(Node));

		list->tail->next->prev = list->tail;
		list->tail = list->tail->next;

		list->tail->data = data;	
	}

	list->listSize++;
	list->tail->next = NULL;
}

void removeBackList(DLinkedList * list)
{
	if(list->listSize == 0)
	{
		printf("List is empty nothing to remove.\n");
	}
	else
	{
		Node * tempNode = list->tail; 

		if(list->listSize == 1)
		{
			list->head = list->tail = list->currentNode = NULL;
		}
		else
		{
			if(list->tail == list->currentNode)
			{
				list->currentNode = list->currentNode->prev; 
			}
			
			list->tail = list->tail->prev;
			list->tail->next = NULL;
		}
	
		--(list->listSize);

		free(tempNode); 
	}
}

void * next(DLinkedList * list)
{
	if(list->currentNode)
	{
		list->currentNode = list->currentNode->next;
	}
	else
	{
		list->currentNode = list->head;
	}

	if(list->currentNode)
	{
		return list->currentNode->data;
	}
	
	return	NULL; 
}

void * previous(DLinkedList * list)
{
	if(list->currentNode)
	{
		list->currentNode = list->currentNode->prev;
	}
	else
	{
		list->currentNode = list->tail;
	}

	if(list->currentNode)
	{
		return list->currentNode->data;
	}
	
	return	NULL; 
}

void * findData( int (*compare)(void * a, void * b), void * data, DLinkedList * list)
{
	for(list->currentNode = list->head; list->currentNode != NULL; list->currentNode = list->currentNode->next)
	{
		if(compare(data,list->currentNode->data) == 0)
		{
			return list->currentNode->data;
		}	
	}

	list->currentNode = list->tail;
	
	return NULL;
}

void removeAll(DLinkedList * list)
{
	while(list->listSize)
	{
		list->currentNode = list->head;
		list->head = list->head->next;
		
		--(list->listSize);
		free(list->currentNode);
		
	}

	list->head = list->tail = list->currentNode = NULL;
}

void printList(DLinkedList* list, void (*printFunc)(void* data))
{
	if(list == NULL)
	{
		printf("List is empty.\n");
	}

	list->currentNode = list->head;
	
	while(list->currentNode != NULL)
	{
		printFunc(list->currentNode->data);
		list->currentNode = list->currentNode->next;
	}

	list->currentNode = list->head;
}


