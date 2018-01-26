/*Assignment name : Assign3
Due Date :			6 January 2018
Submission Date :	6 January 2018
Professor :			ANDREW TYLER
Author:				Jagmandeep Singh
Purpose :		Adding frames to animation using singly linked list
*********************************************************************/
#include <iostream>
#include <time.h>
using namespace std;

#include "Display.h"
#include "SystemMemoryDisplay.h"
#include "GPUMemoryDisplay.h"
/********************************************************************
Function name:	Display()
Purpose:		Copy constructor
In parameters:	int , int , int , char*
Out parameters:	None
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Display::Display(int x, int y, int dur, char* n) {
	pixel_x = x;
	pixel_y = y;
	duration = dur;
	name = n;
}
/********************************************************************
Function name:	Display()
Purpose:		Initialize variables
In parameters:	Display&
Out parameters:	None
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Display::Display(const Display& d) {

	pixel_x = d.pixel_x;
	pixel_y = d.pixel_y;
	duration = d.duration;
	name = new char[strlen(d.name) + 1];/*Alocate memory*/
	strcpy(name, d.name);

}

/********************************************************************
Function name:	operator<<
Purpose:		To display contents
In parameters:	ostream&, Animation&
Out parameters:	ostream&
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
ostream& operator<<(ostream& o, Display& d) {
	time_t startsec, oldsec, newsec;
	startsec = oldsec = time(NULL);
	newsec = time(NULL);
	int counter = 1;
	/*Adding contents into output stream*/
	o << "\tDisplay name = " << d.name << "; pixel_x = " << d.pixel_x 
		<< "; pixel_y = " << d.pixel_y << "; duration = " << d.duration << endl;
	o << "\tCounting the  seconds for this Display";
	while (counter <= d.duration)
	{
		newsec = time(NULL);
		if (newsec > oldsec)
		{
			o << " " << counter++ << ", ";
			oldsec = newsec;
		}
	}
	o << endl;
	o << "\tMemory requirements = " << d.BufferSize() <<" bytes"<< endl; 
	return o;
}
