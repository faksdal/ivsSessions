/*
 * processKeypress.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <iostream>
#include <unistd.h>
#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//	Obtains and processes the user input
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processKeypress(bool& _quit)
{
	int key = readkey(STDIN_FILENO);

	switch(key){
		case TAB:			// Shifts focus to the next filter, updating cursor
							// location at the same time
							nextFilter();
							break;

		case UP_ARROW:		redrawSessions(UP_ARROW);
							break;

		case DOWN_ARROW:	redrawSessions(DOWN_ARROW);
							break;

		case ESC:			// Yeah, user wants to quit this thing...
							_quit = true;
							break;

		case BK_SP:			// Do some fancy editing to remove a character from
							// the active filter.
							// TODO: Maybe move it out of here, for clarity?

							// If the x-value of the cursor, equals the x-value
							// of where the filter is drawn, then we don't move.
							if(c_where.i_column == vl_filter[getActiveFilterIndex()].i_filterColumn)
								break;

							// Erase the last character of the filter text by
							// overwriting it with default color
							print(vl_filter[getActiveFilterIndex()].i_filterColumn
								+ vl_filter[getActiveFilterIndex()].str_filterText.size()
								- 1, 3, d_colors.str_default_color + " ");

							// Move one left
							c_where.i_column--;

							// Knocks one character off of the filter text
							vl_filter[getActiveFilterIndex()].str_filterText.pop_back();

							// Prints the new filter text back
							print(vl_filter[getActiveFilterIndex()].i_filterColumn, 3, d_colors.str_filter_passive_color + vl_filter[getActiveFilterIndex()].str_filterText);

							// And we should be goooooood :-)
							break;

		default:			// Advance the cursor location
							// TODO: Edit this to stay within constraint...
							c_where.i_column++;

							// Convedt to CAPS, and print to terminal
							// I skipped the CAPS
							//std::cout << d_colors.str_filter_passive_color << (char)std::toupper((char)key) << std::flush;
							std::cout << d_colors.str_filter_passive_color << (char)key << std::flush;

							// Append CAPS key to active filter text
							// I skipped the CAPS
							//vl_filter[getActiveFilterIndex()].str_filterText.append(1, (char)std::toupper((char)key));
							vl_filter[getActiveFilterIndex()].str_filterText.append(1, (char)key);

							// Here we need to write some code to apply filter

							break;
	}
	//print(40, 3, "Current highlighted session: ");
	//print(70, 3, "   ");
	//print(70, 3, l_track.ul_current_highlighted_session);
	//print(75, 3, "Current highlighted row: ");
	//print(101, 3, "   ");
	//print(101, 3, l_track.ul_current_highlighted_row);

	setFocusActiveFilter();

}
