/**********************************************************************
Filename:			Frame.cpp
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
Purpose:			Implements functions declaired in Frames.h
*********************************************************************/
#include "Frame.h"
#include <iostream>
using namespace std;
/********************************************************************
Function name:	Frame()
Purpose:		Initilize variables
In parameters:	none
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Frame::Frame(){
	fileName = nullptr;
	pNext = nullptr;
}
/********************************************************************
Function name:	~Frame
Purpose:		This function is a distructor.
In parameters:	none
Out parameters:	none
Version:		1.0
Author:			Jagmandeep Singh
**********************************************************************/
Frame::~Frame() {
	delete[] fileName;
	pNext=nullptr;
}