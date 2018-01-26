/*Class name : Assign2
Due Date : 2017
Submission Date :6 1 2017
Professor : ANDREW TYLER
Author	:	Jagmandeep Singh
Purpose : Building frames for animation using singly linked list
*********************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Display.h"
#include "Frame.h"
#include "GPUMemoryDisplay.h"
#include "SystemMemoryDisplay.h"
/********************************************************************
Function name:	operator+
Purpose:		To concatinate two frames
In parameters:	Frame&
Out parameters:	Frame
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Frame::Frame(const Frame & frame1)
{
	SystemMemoryDisplay * systMem , *sysTemp;
	GPUMemoryDisplay * GPUMem, *GPUTemp;
	for (unsigned int i = 0; i < frame1.displays.size(); i++) {
		if ((sysTemp = dynamic_cast<SystemMemoryDisplay*>(frame1.displays[i])) != nullptr) {
			systMem = new SystemMemoryDisplay(*sysTemp);
			displays.push_back(systMem);
		}
		else if ((GPUTemp = dynamic_cast<GPUMemoryDisplay*>(frame1.displays[i])) != nullptr)
		{
			GPUMem = new GPUMemoryDisplay(*GPUTemp);
			displays.push_back(GPUMem);
		}
	}
	fileName = frame1.fileName;
}
/********************************************************************
Function name:	operator<<
Purpose:		To display contents
In parameters:	ostream&, Animation&
Out parameters:	ostream&
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
ostream& operator<<(ostream& o, Frame& f) {
	SystemMemoryDisplay * systMem;
	GPUMemoryDisplay * GPUMem;
	o << "\tFileName = " << f.fileName << endl;
	/*Loops through display and adds in output stream*/
	for (unsigned int i = 0; i < f.displays.size(); i++) {
		o << "\tDisplay #" << i << ": ";


		if ((systMem = dynamic_cast<SystemMemoryDisplay*>(f.displays[i])) != nullptr) {
			o << "System Memory Display" << endl << *systMem << endl;
		}
		else if((GPUMem = dynamic_cast<GPUMemoryDisplay*>(f.displays[i])) != nullptr)
		{
			o << "GPU Memory Display. Shader = " << GPUMem->GetShader() << endl << *GPUMem << endl;
		}
	}
	return o;
}


