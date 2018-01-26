
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Display.h"
#include "Frame.h"

Frame Frame::operator+(Frame& frame1) {
	string name;
	
	name = frame1.fileName + name;
	vector<Display> newVec;
	newVec.insert(newVec.end(), displays.begin(), displays.end());
	newVec.insert(newVec.end(), frame1.displays.begin(), frame1.displays.end());
	Frame newFrame = Frame(name, newVec);
	return newFrame;
}
ostream& operator<<(ostream& o, Frame& f) {
	vector<Display>::iterator it;
	o << f.fileName;
	for (it = f.displays.begin(); it != f.displays.end(); ++it ) {
		o << *it;
	}
	
	return o;
}

