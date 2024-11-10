/*
 * updateStatusLine.cpp
 *
 *  Created on: 9 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
// Prints out some basic info about sessions
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::updateStatusLine(void)
{
	print(1, d_bound.i_total_rows, d_colors.str_default_color + "         ");
	moveCursor(1, d_bound.i_total_rows);
	std::cout << (l_track.ul_current_highlighted_session + 1) << "/" << visibleSessions() << std::flush;
}
