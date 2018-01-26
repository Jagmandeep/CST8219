
/**********************************************************************
Filename:			Ass1.c
Version:			1.0
Author:				Jagmandeep Singh
Student No:			
Course Name/Number: C++ Programing CST8219
Lab Sect:			300
Assignment #:		00
Assignment name:	Frames
Due Date:			October 14 2017
Submission Date:	October 13 2017
Professor:			ANDREW TYLER
Purpose:			Create main and menue for proper functioning of assignment
*********************************************************************/
// ass1.cpp
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC	// need this to get the line identification
//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF); // in main, after local declarations
//NB must be in debug build

#include <crtdbg.h>
#include "Frame.h"
#include "Animation.h"

#include <iostream>
using namespace std;

bool running = true;
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
	char selection;
	bool running = true;
	Animation A;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // in main, after local declarations

	while (running)
	{
		cout << "MENU\n 1. Insert a Frame\n 2. Delete all the Frames\n 3. Run the Animation\n 4. Quit\n" << endl;

		cin >> selection;

		switch (selection)
		{
		case '1':
			A.InsertFrame();
			break;
		case '2':
			A.DeleteFrames();
			break;
		case '3':
			A.RunFrames();
			break;
		case '4':
			running = false;
			break;
		default:
			break;
		}
	}

	return 0;
}
