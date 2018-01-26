
/**********************************************************************
Filename:			Animation.cpp
Version:			1.0
Author:				Jagmandeep Singh
Student No:			
Course Name/Number: C++ Programing CST8219
Lab Sect:			300
Assignment #:		01
Assignment name:	Assign1
Due Date:			September 14 2017
Submission Date:	September 13 2017
Professor:			ANDREW TYLER
Purpose:			Adding frames to animation using singly linked list
*********************************************************************/
#include "Animation.h"
#include "Frame.h"
#include <iostream>
#include <time.h>
using namespace std;
#pragma once

/********************************************************************
Function name:	Animation
Purpose:		Initilize variables
In parameters:	none
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Animation::Animation() {
	frames = nullptr;
	
}
/********************************************************************
Function name:	~Animation
Purpose:		This function is a distructor.
In parameters:	none
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Animation::~Animation() {
	delete frames;
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
void Animation::InsertFrame() {
	char name[200];
	int numOfFrames = 0, index = 0 ,i = 1;
	Frame *newframe;
	Frame *temp = frames;
	cout << "Insert a Frame in the animation\n" << endl;
	newframe = new Frame();
	/*This asks for name of frame*/
	cout << "Please enter the Frame filename:" << endl;
	cin >> name;
	/*Create space for frame's name*/
	newframe->GetfileName() = new char[strlen(name)+1];
	/*Copy name given by user to our frame fileName*/
	strcpy( newframe->GetfileName(), name);
	newframe->GetpNext() = nullptr;
	/*Checks if we are adding first element into our list*/
	if (frames == nullptr) {
		frames = newframe;
		cout << "This is the first frame in the list" << endl;
	}
	else {
		while (temp != nullptr) {
			numOfFrames++;
			temp = temp->GetpNext();
		}
		cout << "There are "<< numOfFrames << " frame(s) in the list. " << endl;
		cout << "Please specify the position (<= "<< numOfFrames <<") to insert at: " << endl;
		cin >> index;
		/*Adds on head*/
		if (index == 0) {
			newframe->GetpNext() = frames;
			frames = newframe;
		}
		else {
			if (index <= numOfFrames && index >= 0) {
				temp = frames;
				/*Loops till required position(depends on user input)*/
				while (i < index) {
					i++;
					temp = temp->GetpNext();
				}
				/*Inserting frame into our animation list*/
				newframe->GetpNext() = temp->GetpNext();
				temp->GetpNext() = newframe;
			}
			else
				cout << "Invalid entry" << endl;
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
void Animation::DeleteFrames() {
	Frame* temp;
	/*Checks if our list is empty*/
	if (frames == nullptr) {
		cout << "Animation is empty\n" << endl;
		return;
	}
	else {
		/*Loops through whole list and deletes(free mrmory) frames*/
		while (frames != nullptr) {
			temp = frames;
			frames = frames->GetpNext();
			delete temp;
		}
		frames = nullptr;
		cout << "Delete all the frames from the Animation\n" << endl;
	}
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
void Animation::RunFrames() {
	int counter = 0;
	time_t startsec, oldsec, newsec;
	Frame* iterator = frames;
	/*Checks if list is empty*/
	if (frames == nullptr)
	{
		cout << "No frames in the animation\n" << endl;
		return;
	}
	cout << "Run the Animation\n" << endl;
	startsec = oldsec = time(NULL);
	/*Loops through whole list and prints in required format*/
	while (iterator)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			cout << "Frame #"<< counter++ << ", time = "<< newsec - startsec <<" sec\n" << endl;
			cout << "Image file name = "<< iterator->GetfileName() <<"\n" << endl;
			iterator = iterator->GetpNext();
			oldsec = newsec;
		}
	}
}

