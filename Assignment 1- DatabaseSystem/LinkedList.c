#define _CRT_SECURE_NO_WARNINGS
#include "function.h"  
 
static link pHead, pTail;

void InitQueue(void) {

	pHead = pTail = NULL;

}

int IsQueueEmpty(void) {   //Empties the Queue

	return(pHead == NULL);
}

void AddToQueue(link pn) {      //Add the nodes to the Queue

	if (IsQueueEmpty()) {   //If the Queue is empty then add the first node to the Queue and make it the pHead and Tail

		pHead = pTail = pn;
	}
	else {

		pTail->pNext = pn;  //Old tail not points to pn (the node we added)
		pTail = pn;    //pTail points to pn
	}
	pTail->pNext = NULL;

}

link DeQueue(void) {     //removes the nodes from the Queue

	link pTemp;            //Hold the current Head
	if (IsQueueEmpty()) {
		return(NULL);
	}
	else {

		pTemp = pHead;  //pHead is returned and then incremented to next Item
		pHead = pHead->pNext;  //ponts to next Node in list
		return(pTemp);  //Ptemp is original head
	}

}

void Save_List(link pn)
{
	char list_name[] = "List of Files";
	FILE* fp;
	fp = fopen("List of Files", "w+");
	fprintf(fp, pn->Data.file_name_list);
}


void Traveral(void)
{
	link pn;
	pn = pHead;
	while (pn != NULL) {
		printf("%s\n", pn->Data.file_name_list);
		pn = pn->pNext;
	}
}

void Traveral_text(void)
{
	int i = 0;
	link pn = pHead;
	while (pn != NULL) {
		printf("No.%d. Data is:  %s\n",i, pn->Data.file_name_list);
		pn = pn->pNext;
		i++;
	}
}

void traverse()
{
	if (pHead == NULL)
	{
		return;
	}
	printf("No.%d. Data is:  %s\n", pHead->Data.file_name_list);
	traverse(pHead->pNext);

}

void deleteNode(char *text) {
	// Since we know input node is not last node, so nextNode will not be null

	link p = pHead;

	while (strcmp(text, p->Data.file_name_list) != 0)
	{
		p = p->pNext;
	}
	
	link temp = p->pNext;
	strcpy(p->Data.file_name_list, temp->Data.file_name_list);
	p->pNext = temp->pNext;
	temp->pNext = NULL;
	free(temp);
}

link printnode(link ptr)
{
	printf("No. % d.Data is : % s\n",ptr->Data.file_name_list);
	return ptr;
}

link search(char* text)
{

	link current = pHead; // Initialize current
	if (current == NULL) //Reached end of the list
	{
		printf("\n name not found in the database \n");
		return NULL;
	}

	if (strcmp(current->Data.file_name_list, text) == 0)
	{
		printf("\n name found \n");
		printf("\n details are -\n");
		printnode(current);
		return current;
	}
	else
	{
		current = current->pNext;
		return search(text);
	}
}

link move(int key, int lines,link pn)
{
	link temp = pHead;
	link temp_next_elements;
	for (int i = key; i < lines; i++)
	{
		temp = pHead->pNext;
	}

	temp->pNext = pn;
	pn->pNext = temp->pNext;
	
}


