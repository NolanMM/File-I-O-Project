
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <time.h>
#define MAX_DATA_LENGTH 1000
Start_Stopfunction();
Insert_function(const char* name_file);
Delete_function(const char* name_file);
Find_function(const char* name_file);
Random_insert(const char* name_file);
Store_Thefile(const char* name_file);
menu_function(int num, const char* name_file);

// FILE I/O

void Open_New_File();
void Open_exist_File();
void Print_List_Files(const char* file_name);

// Linked List

typedef struct node Node;
typedef struct item Item;
typedef Node* link;

struct item {

	char file_name_list[1000];
};

struct node {

	link pNext;
	Item Data;
};

//Queue Function Prototypes
long int* fDataIndices(int numQuotes, const char* file_name);
int fnumData(const char* file_name);
int* fDataLength(int numQuotes, long int* quoteIndices);
int GetDataFromFile(char* buff, int DataLength, int user_choose_the_order_of_data, int numQuotes, long int* quoteIndices, int* quoteLengths, const char* file_name);

void InitQueue(void);
int IsQueueEmpty(void);
void AddToQueue(link);
link DeQueue(void);
void Traveral(void);
void Save_List(void);
#pragma once
#pragma once
