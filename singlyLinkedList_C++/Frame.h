/**********************************************************************
Filename:			Frame.h
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
Purpose:			Create Function prototypes
*********************************************************************/
// Frame.h
#pragma once

class Frame {
	char* fileName;
	Frame* pNext;
public:
	Frame();
	~Frame();
	char*& GetfileName() { return fileName; }
	Frame*& GetpNext() { return pNext; };
};
