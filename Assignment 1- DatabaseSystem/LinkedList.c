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


