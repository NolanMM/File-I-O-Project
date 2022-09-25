#define _CRT_SECURE_NO_WARNINGS
#include "function.h"


void Open_New_File()
{
	char file_name[1000];
	link p;
	printf("Please enter the file name you want:");
	scanf("%s",file_name);
	char* name_file = file_name;
	

	p = (link)malloc(sizeof(Node));      //Create the Node for the message
	strcpy(p->Data.file_name_list, file_name);
	AddToQueue(p);
	Traveral();
	Save_List(p);
	FILE* fp;
	fp = fopen(name_file, "a");
	menu_function(2,name_file);
	fclose(fp);
	
}

void Open_exist_File()
{
	Print_List_Files("List of Files");
	char file_name[1000];
	printf("Please enter the file name you want to modify:");
	scanf("%s", file_name);
	char* name_file = file_name;
	FILE* fp;
	fp = fopen(name_file, "a");

	menu_function(2,name_file);
	fclose(fp);

}