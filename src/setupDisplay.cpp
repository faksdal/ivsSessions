/*
 * setupDisplay.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
//
// Sets up the display:
//		* clears the screen
//		* set the various display parameters
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::setupDisplay(void)
{
	saveTerminalState();
	clearScreen();
	getTerminalSize();	// loads terminal size into memory, rows and columns

	// Initialize some variables...
	d_bound.i_header1_row = 1;
	d_bound.i_header2_row = 2;
	d_colors.str_headerColor = "\033[40;00m";


	//db.terminal_header_1_row	= 2;
	//db.terminal_header_2_row	= 3;
	//db.terminal_list_start_row	= db.terminal_header_2_row + 2;
	//db.terminal_list_end_row	= db.terminal_rows - 3;

	//print(1, 3, "Filter:");
}
