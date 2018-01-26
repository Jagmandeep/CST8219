
/**********************************************************************
Filename:			Animation.cpp
Version:			1.0
Author:				Jagmandeep Singh
Student No:			
Course Name/Number: C++ Programing CST8219
Lab Sect:			300
Assignment #:		01
Assignment name:	Assign2
Due Date:			 2017
Submission Date:	 2017
Professor:			ANDREW TYLER
Purpose:			Adding frames to animation using singly linked list
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "Animation.h"

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
	string fileName;
	int x ,y , dur, displayNum;
	char dispName[200];
	char* name;
	vector<Display> vec;

	cout << "Insert a Frame in the animation\n" << endl;
	cout << "Please enter the Frame filename:" << endl;
	cin >> fileName;
	//frame done
	cout <<  "the Frame Displays(the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays:" << endl;
	cin >> displayNum;
	
	for (int i = 0; i < displayNum; i++) {
		cout << "Please enter pixel x for Display #" << i << "pixel_x:" << endl;
		cin >> x;
		cout << "Please enter pixel y for Display #" << i << "pixel_y:" << endl;
		cin >> y;
		cout << "Please enter the duration sec for this Display:" << endl;
		cin >> dur;
		cout << "Please enter the name for this Display:" << endl;
		cin >> dispName;
		name = new char[strlen(dispName) + 1];
		strcpy(name, dispName);
		
		vec.push_back(Display(x, y, dur, name));
	}
	if (frames.empty()) {
		cout << "this is the first frame: " << endl;
		Frame newframe = Frame(name, vec);
		frames.push_front(newframe);
	}
	else {
		Frame newframe = Frame(name, vec);
		frames.push_front(newframe);
	}
	
}

void Animation::DeleteFrames() {

	frames.clear();

}

Frame& Animation::operator[](unsigned int i){
	
	forward_list<Frame>::iterator it;
	int position = 0;
	for (it = frames.begin(); it != frames.end(); ++it) {
		if (position == i) {
			return *it;
		}
		position++;
	}

}

void Animation::operator+=(Frame& f){
	frames.push_front(f);
}

ostream& operator<<(ostream& o, Animation& a) {
	forward_list<Frame>::iterator iterator;
	for (iterator = a.frames.begin(); iterator != a.frames.end(); ++iterator) {
		o << *iterator;
	}
	return o;
}
