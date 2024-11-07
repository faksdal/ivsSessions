/*
 * clearLines.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Clears _numLines lines starting from row _startLine
// The row one is 1, not 0
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::clearLines(int _startLine, int _numLines)
{
	for (int i = 0; i < _numLines; ++i) {
		std::cout << "\033[" << _startLine + i << ";1H"; // Move cursor to specific line and start of line
		std::cout << "\033[2K";                         // Clear the entire line
	}
}
