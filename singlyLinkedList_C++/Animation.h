/**********************************************************************
Filename:			Animation.h
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
//Animation.h
#include "Frame.h"
#include <iostream>
using namespace std;
#pragma once

class Animation {
	Frame* frames;
public:
	Animation();
	~Animation();
	void InsertFrame();
	void DeleteFrames();
	void RunFrames();
};
