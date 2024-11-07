/*
 * setupDisplay.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
// Sets up the display:
//		* clears the screen
//		* sets the various display parameters
//		* sets the color scheme
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::setupDisplay(void)
{
	saveTerminalState();
	clearScreen();
	getTerminalSize();	// loads terminal size into memory, rows and columns

	// Default color init
	d_colors.str_default_color	= "\033[40;00m";

	// Initialize header vars
	d_bound.i_header1_row		= 1;
	d_bound.i_header2_row		= 2;
	d_colors.str_header_color	= "\033[40;00m";

	// Initialize filter vars
	d_bound.i_filter_row				= 3;
	d_colors.str_filter_active_color	= "\033[30;102m";
	d_colors.str_filter_passive_color	= "\033[30;47m";


	//db.terminal_header_1_row	= 2;
	//db.terminal_header_2_row	= 3;
	//db.terminal_list_start_row	= db.terminal_header_2_row + 2;
	//db.terminal_list_end_row	= db.terminal_rows - 3;

	//print(1, 3, "Filter:");
}
