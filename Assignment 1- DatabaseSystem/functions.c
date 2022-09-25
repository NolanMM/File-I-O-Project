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

	menu_function(2, name_file);

}



Delete_function(const char* name_file)
{
	int i = 0;
	char(*n)[1000]; /* pointer to an array of 1000 chars */
	FILE* fp;


	fp = fopen(name_file, "r");

	char delete_text[40];
	link q;

	if (fp == NULL)
	{
		fprintf(stderr, "ERROR\n");
		return EXIT_FAILURE;
	}

	n = malloc(sizeof(*n));

	if (n == NULL)
	{
		fprintf(stderr, "ERROR\n");
		return EXIT_FAILURE;
	}

	while (fgets(n[i++], 1024, fp) != NULL) /* strcpy is redundant here,since we can just save in the buffer directly*/
	{
		n = realloc(n, (i + 1) * sizeof(*n)); /* realloc each time so you can store another string */

		if (n == NULL)
		{
			fprintf(stderr, "ERROR\n");
			return EXIT_FAILURE;
		}
	}
	

	for (int j = 0; j < i - 1; j++)
	{
		q = (link)malloc(sizeof(Node));      //Create the Node for the message
		strcpy(q->Data.file_name_list, n[j]);
		AddToQueue(q);
	}

	Traveral_text();

	int k = 0;

	printf("\nPlease enter the order of data you want to delete:");
	scanf("%s", &delete_text);
	search(delete_text);
	free(n);
	menu_function(2, name_file);
	fclose(fp);
}

Find_function(const char* name_file)
{
	char* find_text;
	printf("\nPlease enter the order of data you want to Find:");

	int i = 0;
	char(*n)[1000]; /* pointer to an array of 1000 chars */
	FILE* fp;


	fp = fopen(name_file, "r");

	char delete_text[40];
	link q;

	if (fp == NULL)
	{
		fprintf(stderr, "ERROR\n");
		return EXIT_FAILURE;
	}

	n = malloc(sizeof(*n));

	if (n == NULL)
	{
		fprintf(stderr, "ERROR\n");
		return EXIT_FAILURE;
	}

	while (fgets(n[i++], 1024, fp) != NULL) /* strcpy is redundant here,since we can just save in the buffer directly*/
	{
		n = realloc(n, (i + 1) * sizeof(*n)); /* realloc each time so you can store another string */

		if (n == NULL)
		{
			fprintf(stderr, "ERROR\n");
			return EXIT_FAILURE;
		}
	}


	for (int j = 0; j < i - 1; j++)
	{
		q = (link)malloc(sizeof(Node));      //Create the Node for the message
		strcpy(q->Data.file_name_list, n[j]);
		AddToQueue(q);
	}

	scanf("%s", &find_text);
	search(find_text);
	menu_function(2, name_file);
	fclose(fp);
}

Random_insert(const char* name_file)
{

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
	printf("Here is the list of file you be created\n");
	do
	{
		temp = fgetc(fp);
		if (feof(fp))
		{
			break;
		}
		printf("%c", temp);
	} while (1);
	puts("");
}


int fnumData(const char*file_name)									// Function returns number of quotes in the file (only need to run once)
{
	FILE* fp;
	
	char c;
	int count = 0;  // Line counter (result)
	// Open the file
	fp = fopen(file_name, "r");

	// Check if file exists
	if (fp == NULL)
	{
		printf("Could not open file %s", file_name);
		return 0;
	}

	// Extract characters from file and store in character c
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n') // Increment count if this character is newline
			count = count + 1;
	// Close the file
	fclose(fp);
	return count;
}
