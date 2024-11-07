/*
 * run.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
int ivsSessions::run(void)
{
	bool	b_quit = false;


	// Call readFile to read inputfile and populate str_inputBuffer.
	readFile();

	// Parse the input buffer, and populate sessions list
	parser();

	// Sets up display for use
	setupDisplay();

	// Prints header text to terminal
	printHeaders();

	// Prepares and prints filter input fields
	setupFilters();

	enableRawmode();
	setActiveFilter();
	setColor("\033[31;41m");
	std::cout << "\x1b[0 q" << std::flush;
	moveCursor(5, 3);
	showCursor();

	while(!b_quit){
		processKeypress(b_quit);
		// here, I can do other stuff

	} // while(!quit)

	disableRawmode();

	// Restore terminal state before we exit
	restoreTerminalState();


	// Reset color and print a new line before exiting
	resetColor();
	std::cout << "\r\n" << std::flush;

	return(0);
}
