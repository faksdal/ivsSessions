/*
 * clearScreen.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */
//#include <iostream>
#include <unistd.h>		// STDOUT_FILENO
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Clears the entire terminal window using write()
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::clearScreen(void)
{
	// Clear the terminal
	//std::cout << "\033[2J\033[1;1H" << std::flush;
	write(STDOUT_FILENO, "\x1b[2J", 4);
}
