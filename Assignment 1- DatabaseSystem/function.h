
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <errno.h>
#include <stdbool.h>
#include <time.h>
#define MAX_DATA_LENGTH 1000
#define MAX_TEXT_CHARACTERS 100000
#define MAX_QUOTE_LENGTH 140
Start_Stopfunction();
Insert_function(const char* name_file);
Delete_function(const char* name_file);
Find_function(const char* name_file);
Random_insert(const char* name_file);
Store_Thefile(const char* name_file, char* buff[]);
menu_function(int num, const char* name_file);
int frandNum(int min, int max);
// FILE I/O

void Open_New_File();
void Open_exist_File();
void Print_List_Files(const char* file_name);

// Linked List
link move(int key, int lines, link pn);
typedef struct node Node;
typedef struct item Item;
typedef struct text_file_data Text_File_Data;
typedef Node* link;
void deleteNode(char*text);

struct item {

	char file_name_list[1000];
};


struct node {

	link pNext;
	Item Data;
};

//Queue Function Prototypes
void Traveral_text(void);
void InitQueue(void);
int IsQueueEmpty(void);
void AddToQueue(link);
link DeQueue(void);
void Traveral(void);
link printnode(link ptr);
void Save_List(link pn);
void traverse();
link search(char* text);

#pragma once
#pragma once
