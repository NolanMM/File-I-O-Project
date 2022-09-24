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
	Store_Thefile(name_file);
	Traveral();
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
	// Initialize the variables
	int  i, j;
	int numDataLines;                    // Number of quotes in the file
	long int LinesIndices;            // Array of quote locations in the file (index correspondes to quote number)
	int* LineLengths;                // Array of quote lengths (index correspondes to quote number)
	int* lengthList;
	char testBuff[1000];  // Result of our getmessage function
	srand(time(NULL));                // Seeds rand()

	//node variables
	link q, p;         //node p and q used to add and remove from queue               

	//run these once to intialize them
	numDataLines = fnumData(name_file);   // Number of Lines
	lengthList = (int*)malloc(numDataLines * sizeof(int));;		// store the length of each lines	
	LinesIndices = fDataIndices(numDataLines,name_file); // Index locations of the quotes
	int o = 0;
	for (int p = 0; p < numDataLines;p++)
	{
		LineLengths = fDataLength(numDataLines, LinesIndices,o );   // Length each lines in the data file
		lengthList[p] = LineLengths;
		o++;
	}
	p = (link)malloc(sizeof(Node));      //Create the Node for the message
	InitQueue();                         //Initialize queue

	for (j = 0; j < numDataLines; j++)              //Creating 'N' number of nodes
	{
		//Get the random message from the file
		GetDataFromFile(testBuff, MAX_DATA_LENGTH, j, numDataLines, LinesIndices, lengthList[j],name_file);  // Later replace testBuff with 'node->msg.buff' which is a member of a node struct
		strcpy(p->Data.file_name_list, testBuff);                  //store the quotes into the node
		AddToQueue(p);                                      //adds node p to the queue
		if (j + 1 != numDataLines) {                                     //adds new nodes based on how many the user wanted
			p->pNext = malloc(sizeof(Node));                //mallocs new nodes only if this is the last loop so there isnt an extra
			p = p->pNext;                                   //set p to point to the next element in the linked list
		}
	}
	free(lengthList);
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


// Function returns an array that indicates the start of every quote in the file (number of characters from the start of the file)
long int* fDataIndices(int numQuotes,const char*file_name)						//numQuotes is the number of quotes in .txt file
{															//fquoteIndices returns a dereferenced pointer because we will return a pointer array
	FILE* fp;												//define the file
	errno_t err;											//used to detect issues with fopen_s

	char c;                                                                     //tests for end of file
	int i = 0;                                                                  //counts how many loops have been done to increment the array
	long int* indexList = (long int)malloc(numQuotes * sizeof(long long int) * 100000);		//this enables the creation of a dynamic array that will have enough space for an array of large numbers
	char* bufIndex = (char)malloc(numQuotes * sizeof(long long int) *100000);
	int indices = 0;                                                            //counts how many characters into the file the 'cursor' is
	if ((err = fopen_s(&fp, file_name, "r")) == 0)
	{
		while (fgets(bufIndex, sizeof(bufIndex), fp) != NULL) {	//fgets stops at \n characters and eof, so we can use it to grab one line at a time
			if (bufIndex[0] == '\\' && bufIndex[1] == 'n') {		//fgets puts each character from the line into bufIndex, so if both element [0] and [1] are '%' then it is the start of a quote
				indexList[i] = ftell(fp);						//ftell reads how many characters from the start of file to the 'cursor' so if the 'cursor' is at the begining of a file, thats the index
				i++;											//move to find next quote index
			}
		}
		indexList[i] = ftell(fp);		//set the eof as the last index, so we can find the quote length of the last quote
		free(bufIndex);					//free the temporary array as we no longer need it
		fclose(fp);						//close the file
		return(indexList);				//return the array of indices
	}
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
	printf("The file %s has %d lines\n ", file_name, count);

	return 0;
}

// Function returns the length of every quote in an array
int* fDataLength(int numQuotes, long int* quoteIndices) // We have to find the start of the code in the file first
{
	int *qLen;
	qLen = (int)malloc(numQuotes * sizeof(long long int) * 100000);//array of sizeof(int) times the number of quotes
	int j;
	for (j = 0; j < numQuotes; j++) {						//for loop to create an array element for each quote that will store the length of that quote
		qLen[j] = quoteIndices[j + 1] - quoteIndices[j];	//qLen is the start of the quote ahead of current quote - start of current quote
	}															//the minus 6 is because quoteIndices starts before the %%\n characters

	return(qLen);
}

int GetDataFromFile(char* buff, int DataLength, int user_choose_the_order_of_data, int numQuotes, long int* quoteIndices, int* quoteLengths,const char*file_name)
{
	FILE* fp;					//define the file
	errno_t err;				//used to detect issues with fopen_s
	int i;						//for loop counter

	if ((err = fopen_s(&fp, file_name, "r")) == 0) {	//test if file opens correctly

		fseek(fp, quoteIndices[user_choose_the_order_of_data], SEEK_SET);		//moves 'cursor' to the start of the randomly chosen quote
		for (i = 0; i < DataLength; i++) {					//now that iLen is the correct size lets set each element in buff to a character of the quote
			buff[i] = fgetc(fp);
		}
		buff[i - 1] = '\0';								//all strings must end in a termination character
		//this character has to be at element 140 or less, otherwise buff becomes corrupted

		fclose(fp);
		return(0);										//no need to return buff since we do it by reference
	}
	
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