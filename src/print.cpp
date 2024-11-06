/*
 * print.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Prints _text to the terminal at column _x and row _y
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::print(int _x, int _y, std::string _text)
{
	hideCursor();
	std::cout << "\033[" << _y << ";" << _x << "H" << _text << std::flush;
	showCursor();
}



void ivsSessions::print(int _x, int _y, unsigned long _text)
{
	hideCursor();
	std::cout << "\033[" << _y << ";" << _x << "H" << _text << std::flush;
	showCursor();
}
