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

	// Parse str_inputBuffer, and populate sessions list
	parser();

	// Sets up display for use
	setupDisplay();

	// Prints header text to terminal
	printHeaders();

	// Prepares and prints filters
	setupFilters();

	// Initialize list tracking variables
	l_track.ul_current_highlighted_session	= 0;
	l_track.ul_current_topmost_session		= 0;

	// Print session list to terminal
	//std::cout << d_colors.str_default_color << vl_sessionList[0].str_sessionCode << std::flush;
	redrawSessions(0);

	// Set keyboard input in raw mode
	enableRawmode();

	// Shift focus to the active filter, and update cursor location
	setFocusActiveFilter();

	// This is the main loop of this circus
	while(!b_quit){
		processKeypress(b_quit);
		// Here, I can do other stuff. Coffee anyone?

	} // while(!quit)

	// Reset keyboard to previous state
	disableRawmode();

	// Restore terminal state before we exit
	restoreTerminalState();


	// Reset color and print a new line before exiting
	resetColor();
	std::cout << "\r\nThank you for using ivsSessions v1\r\n" << std::flush;

	return(0);
}
