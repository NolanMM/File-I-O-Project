#define _CRT_SECURE_NO_WARNINGS
#include "function.h"

Start_Stopfunction()
{
	printf("************************************\n");
	printf("*       We manage your File        *\n");
	printf("* PLease Type the number you choose*\n");
	printf("*                                  *\n");
	printf("*   1. Open new file               *\n");
	printf("*   2. Open exist file             *\n");
	printf("*   3. Exit                        *\n");
	printf("*             Thank you!           *\n");
	printf("************************************\n");
	int choice1;	// Take the choice from user to direct the program into the function

	printf("PLease enter here:");
	scanf("%d", &choice1);

	switch (choice1)
	{
	case 1:
		Open_New_File();
		break;
	case 2:
		Open_exist_File();
		break;
	case 3:
		break;
	default:
		break;
	}
}

Insert_function(const char* name_file)
{
	FILE* fp;
	fp = fopen(name_file, "a");
	char inputdata[1000];
	printf("Input the Data you want: \n");
	scanf("%s", inputdata);
	fprintf(fp, "%s\n", inputdata);
}

Delete_function(const char* name_file)
{
	FILE* fp;
	fp = fopen(name_file, "r");
	char inputdata[1000];

	// List of data
	// Have to scanf and store all the data into a new list and modified it
	Print_List_Files(name_file);
	printf("Input the Data you want to delete: \n");
	scanf("%s", inputdata);
}

Find_function(const char* name_file)
{

}

Random_insert(const char* name_file)
{

}

Store_Thefile(const char* name_file)
{
	FILE* fp;
	fp = fopen(name_file, "r");

	int temp;
	InitQueue();
	do
	{
		temp = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", temp);
	} while (1);
}

menu_function(int num,const char *name_file)
{
	switch (num)
	{
	case 1:
		printf("************************************\n");
		printf("*   Welcome to the Data Machine    *\n");
		printf("* PLease Type the number you choose*\n");
		printf("*         or Start or Stop         *\n");
		printf("*   1. Start                       *\n");
		printf("*   2. Stop                        *\n");
		printf("************************************\n");
		printf("*             Thank you!           *\n");
		printf("************************************\n");
		break;
	case 2:
		printf("************************************\n");
		printf("*   We connect with the datafile   *\n");
		printf("* PLease Type the number you choose*\n");
		printf("*                                  *\n");
		printf("* 1. Insert Data                   *\n");
		printf("* 2. Delete Data                   *\n");
		printf("* 3. Find Data                     *\n");
		printf("* 4. Random Insert                 *\n");
		printf("* 5. Open New File                 *\n");
		printf("* 6. Open exist File               *\n");
		printf("* 7. Return                        *\n");
		printf("* 8. Exit                          *\n");
		printf("*             Thank you!           *\n");
		printf("************************************\n");
		int choice;	// Take the choice from user to direct the program into the function

		printf("\nPLease enter here:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			Insert_function(name_file);
			break;
		case 2:
			Delete_function(name_file);
			break;
		case 3:
			Find_function(name_file);
			break;
		case 4:
			Random_insert(name_file);
			break;
		case 5:
			Open_New_File(name_file);
			break;
		case 6:
			Open_exist_File(name_file);
			break;
		case 7:
			menu_function(2, name_file);
			break;
		case 8:
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void Print_List_Files(const char*file_name)
{
	FILE* fp;
	fp = fopen(file_name, "r");

	int temp;
	if ((fp = fopen(file_name, "r")) == NULL) {
		printf("Error! opening file");
		// Program exits if the file pointer returns NULL.
		exit(1);
	}

	do
	{
		temp = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", temp);
	} while (1);
}


// Draft 
/*
///////////////////////////////////////////////////////////
//Menu modified
	printf("************************************\n");
	printf("*   We connect with the datafile   *\n");
	printf("* PLease Type the number you choose*\n");
	printf("*                                  *\n");
	printf("* 1. Insert Data                   *\n");
	printf("* 2. Delete Data                   *\n");
	printf("* 3. Find Data                     *\n");
	printf("* 4. Random Insert                 *\n");
	printf("* 5. Exit                          *\n");
	printf("*             Thank you!           *\n");
	printf("************************************\n");

	int choice;	// Take the choice from user to direct the program into the function

	printf("PLease enter here:");
	scanf_s("%d", &choice, sizeof(int));

	switch (choice)
	{
		case 1:
			Insert_function();
			break;
		case 2:
			Delete_function();
			break;
		case 3:
			Find_function();
			break;
		case 4:
			Random_insert();
			break;
		case 5:
			break;
	default:
		break;
	}
//////////////////////////////////////////////////////////
*/