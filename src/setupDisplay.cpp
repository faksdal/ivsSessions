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
	getTerminalSize();	// loads terminal size into vars, rows and columns

	// Default color init
	d_colors.str_default_color			= "\033[40;00m";
	d_colors.str_list_highlighted_color	=	"\033[30;102m";

	// Initialize header vars
	d_bound.i_header1_row		= 1;
	d_bound.i_header2_row		= 2;
	d_colors.str_header_color	= "\033[40;00m";

	// Initialize filter vars
	d_bound.i_filter_row				= 3;
	d_colors.str_filter_active_color	= "\033[30;102m";
	d_colors.str_filter_passive_color	= "\033[30;47m";

	// Set display size vars
	d_bound.i_list_start_row	= d_bound.i_filter_row + 1;
	d_bound.i_list_end_row		= d_bound.i_total_rows - 2;
}
