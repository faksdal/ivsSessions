/*
 * getTerminalSize.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include <unistd.h>		// STDOUT_FILENO, TIOCGWINSZ
#include <sys/ioctl.h>	// struct winsize
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Stores termianl size in object variables
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::getTerminalSize(void)
{
	struct	winsize	ws;

	// Use ioctl() to get the window size
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
		std::cerr << "Error: Unable to get terminal size" << std::endl;
		return;
	}

	// Store terminal size
	d_bound.i_total_columns	= ws.ws_col;
	d_bound.i_total_rows	= ws.ws_row;
}
