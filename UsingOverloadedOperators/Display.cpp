
#include <iostream>
using namespace std;

#include "Display.h"

Display::Display(int x , int y, int dur, char* n) {
	pixel_x = x;
	pixel_y = y;
	duration = dur;
	name = n;
}
Display::Display(const Display& d) {
	
	pixel_x = d.pixel_x;
	pixel_y = d.pixel_y;
	duration = d.duration;
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
}

Display::~Display() {
	delete name;
}

ostream& operator<<(ostream& o, Display& d) {
	o << d.pixel_x << d.pixel_y << d.duration << d.name;
	return o;
}