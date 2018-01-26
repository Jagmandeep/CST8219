
/**********************************************************************
Filename:			ass0.c
Version:			1.0
Author:				Jagmandeep Singh
Student No:			
Course Name/Number: C++ Programing CST8219
Lab Sect:			300
Assignment #:		00
Assignment name:	Frames
Due Date:			September 24 2017
Submission Date:	September 23 2017
Professor:			ANDREW TYLER 
Purpose:			Adding frames to animation using singly linked list
*********************************************************************/
// ass0.c
#define _CRT_SECURE_NO_WARNINGS

#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum { FALSE = 0, TRUE } BOOL;

struct Frame {
	char* fileName;
	struct Frame* pNext;
};

struct Animation {
	struct Frame* frames;
};

// Forward declarations
void initAnimation(struct Animation*);
void insertFrame(struct Animation*);
void deleteFrames(struct Animation*);
void runFrames(struct Animation*);

/********************************************************************
Function name:	main
Purpose:		main function
				Takes input from user whether to insert, delete, display frames or quit
In parameters:	none
Out parameters:	0 for successful execution
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
int main(void)
{
	char response;
	BOOL RUNNING = TRUE;
	struct Animation A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	initAnimation(&A);

	while (RUNNING)
	{
		printf("MENU\n 1. Insert a Frame\n 2. Delete all the Frames\n 3. Run the Animation\n 4. Quit\n");
		scanf("%c", &response);
		switch (response)
		{
		case '1':insertFrame(&A); break;
		case '2':deleteFrames(&A); break;
		case '3':runFrames(&A); break;
		case '4':RUNNING = FALSE; deleteFrames(&A); break;
		default:printf("Please enter a valid option\n");
		}
		printf("\n");
		while ((response = getchar()) != '\n' && response != EOF);// clear input buffer
	}
	return 0;
}

/********************************************************************
Function name:	runFrames
Purpose:		runFrames function
				displays all frames in animation
In parameters:	pointer to animation
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
void runFrames(struct Animation* pA)
{
	int counter = 0;
	time_t startsec, oldsec, newsec;
	struct Frame* iterator = pA->frames;

	if (pA->frames == 0)
	{
		printf("No frames in the animation\n");
		return;
	}

	printf("Run the Animation\n");
	startsec = oldsec = time(NULL);
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			printf("Frame #%d, time = %d sec\n", counter++, newsec - startsec);
			printf("Image file name = %s\n", iterator->fileName);
			iterator = iterator->pNext;
			oldsec = newsec;
		}
	}
}

/********************************************************************
Function name:	initAnimation
Purpose:		initAnimation function
				just initializes the animation
In parameters:	pointer to animation
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/

void initAnimation(struct Animation* ptr) {

	ptr->frames = 0;

}

/********************************************************************
Function name:	insertFrame
Purpose:		insertFrame  function
				inserts frames in animation at position specified by user.
In parameters:	pointer to animation
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/

void insertFrame(struct Animation* pA) {
	int count = 0, index = 0, i = 1;
	char name[50];
	
	struct Frame* temp = pA->frames;
	printf("Insert a Frame in the Animation\n");
	printf("Please enter the Frame filename of frame: ");
	scanf("%s", name);

	struct Frame* new = (struct Frame *) malloc(sizeof(struct Frame));
	new->fileName = (char *) malloc(strlen(name) + 1);
	strcpy(new->fileName, name);
	new->pNext = 0;

	if (pA->frames == 0) {
		pA->frames = new;			/* Adds frame in animation on head*/
		printf("This is the first Frame in the list\n");	
	}

	else {	
		while (temp != 0) {
			count++;
			temp = temp->pNext;
		}	
		printf("There are %d frame(s) in the list. ", count);
		printf("Please specify the position (<= %d) to insert at: ", count);
		scanf("%d", &index);

		if (index == 0) {
			new->pNext = pA->frames;
			pA->frames = new;
		}	
		else if(index <= count && index >= 0){
			temp = pA->frames;
			while (i < index) {
				temp = temp->pNext;
				i++;
			}
			new->pNext = temp->pNext;
			temp->pNext = new;
		}
		else {
			printf("Invalid entry\n");
		}
	}
}

/********************************************************************
Function name:	deleteFrames
Purpose:		deleteFrames  function
				deletes all frames in animation and frees memory.
In parameters:	pointer to animation
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/

void deleteFrames(struct Animation* pA) {
	struct Frame* temp = pA->frames;
	printf("Delete all the frames from the Animation\n");
	while (temp != 0) {		
		free(temp->fileName);	
		pA->frames = temp->pNext;	
		free(temp);	
		temp = pA->frames;
	}	
	pA->frames = NULL;	
}