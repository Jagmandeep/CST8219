/*Assignment name : Assign3
Due Date :			6 January 2018
Submission Date :	6 January 2018
Professor :			ANDREW TYLER
Author:				Jagmandeep Singh
Purpose :		Adding frames to animation using singly linked list
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
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
	int x, y, dur, displayNum, type;
	char dispName[200];
	char* name;
	string typeName;
	int position = 0, i = 0, counter;
	vector<Display*> vec;
	forward_list<Frame>::iterator it;
	cout << "Insert a Frame in the animation" << endl;
	cout << "Please enter the Frame filename: ";
	cin >> fileName;
	//frame done
	cout << "Entering the Frame Displays(the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Displays: ";
	cin >> displayNum;

	for (int i = 0; i < displayNum; i++) {
		cout << "Please enter pixel x for Display #" << i << " pixel_x: ";
		cin >> x;
		cout << "Please enter pixel y for Display #" << i << " pixel_y: ";
		cin >> y;
		cout << "Please enter the duration sec for this Display: ";
		cin >> dur;
		cout << "Please enter the name for this Display: ";
		cin >> dispName;
		name = new char[strlen(dispName) + 1];
		strcpy(name, dispName);
		cout << "Please enter the type for this display (1 = SystemMemoryDisplay, 2 = GPUMemoryDisplay):";
		cin >> type;
		if (type == 1) {
			vec.push_back(new SystemMemoryDisplay(x, y, dur, name));

		}
		else if (type == 2) {
			cout << "Please enter the file name of the associated GPU Shader:";
			cin >> typeName;
			vec.push_back(new GPUMemoryDisplay(x, y, dur, name, typeName));
		}
	}

	/*	Frame newframe = Frame(fileName, vec);	*/
	Frame *newframe = new Frame(fileName, vec);
	if (frames.empty()) {
		cout << "\nThis is the first frame in the list\n" << endl;
		frames.push_front(*newframe);
	}
	else {
		counter = 0;
		for (it = frames.begin(); it != frames.end(); ++it) {
			counter++; /* counts how many objects in the list*/
		}
		if (counter <= 1) {
			it = frames.begin(); /* restes iterator*/
			frames.insert_after(it, *(newframe)); /* adds 2nd object*/
		}
		else {
			cout << "There are " << counter << " Frame(s) in the list" << endl;
			cout << "Please specify the position, between 0 and " << counter - 1 << " to insert after : "; 
			/*get position from user*/
			cin >> position;

			if (position > counter || position < 0) { /* checks for boundaries*/
				return;
			}
			it = frames.begin();

			for (i = 0; i < position; i++) { /* counters frames in list*/
				++it;
			}
			if (counter == position) { /* insert frame at specified position*/
				it = frames.begin();
				frames.insert_after(it, *(newframe));
			}
			else {
				frames.insert_after(it, *(newframe));
				it = frames.begin();
			}
		}
	}
	delete newframe;
}
/********************************************************************
Function name:	DeleteFrames
Purpose:		distructor
In parameters:	none
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
void Animation::DeleteFrames() {
	if (frames.empty()) {
		cout << "Animation is empty !" << endl;
	}
	else {
		frames.clear();
		cout << "Frames deleted !" << endl;
	}
}
/********************************************************************
Function name:	operator<<
Purpose:		To display contents
In parameters:	ostream&, Animation&
Out parameters:	ostream&
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
ostream& operator<<(ostream& o, Animation& a) {
	unsigned int i = 0;

	forward_list<Frame>::iterator iterator;
	if (a.frames.empty()) {
		cout << "Animation is empty" << endl;
	}
	/*Adding contents to output stream according to specification*/
	else {
		o << "Animation A\n" << "Run the animation" << endl;
		for (iterator = a.frames.begin(); iterator != a.frames.end(); ++iterator) {
			o << "Frame #" << i << ":" << endl;

			o << *iterator;
			i++;
		}
	}
	o << "Output finished" << endl;
	return o;
}