/*
 * scrollSessionList.cpp
 *
 *  Created on: 8 Nov 2024
 *      Author: jole
 */
#pragma GCC diagnostic ignored "-Wsign-compare" (d_bound.i_list_end_row > l_track.ul_current_highlighted_row)

#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Scrolls the list in the terminal
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::scrollSessionList(int _direction, int _numberOfLines)
{
	int row;

	switch(_direction){
		case UP_ARROW:		// Let's start by decreasing the top-most items index
							l_track.ul_current_topmost_session--;

							// reset the row variable
							row = d_bound.i_list_start_row;

							// Print every visible session from top
							for(unsigned long i = l_track.ul_current_topmost_session; i < vl_sessionList.size(); i++){

								// If item is visible, print it
								if(vl_sessionList[i].b_visible){
									printSession(row++, i, d_colors.str_default_color);
								} // if(vl_sessionList[i].b_visible)

								// Break if we hit bottom
								if(row >= d_bound.i_list_end_row)
									break;
							} // for(unsigned long i = l_track.ul_current_topmost_session; i < vl_sessionList.size(); i++)
							// Highlight the first line in the list
							printSession(d_bound.i_list_start_row, l_track.ul_current_topmost_session, d_colors.str_list_highlighted_color);

							// Update tracking for current highlighted session
							l_track.ul_current_highlighted_session--;
							return;

		case DOWN_ARROW:	// If we are at the bottom of the screen, we must check to see if
							// there are more sessions to be shown, and thus scroll the list.
							// However, should we be at the bottom, AND the last visible session
							// is shown - we do nothing

							// Check if we're at the bottom of the screen...
							if(l_track.ul_current_highlighted_row == d_bound.i_list_end_row){

								// ...and if we are, we re-draw the whole list.

								// Let's start by increasing the top-most items index
								l_track.ul_current_topmost_session++;

								// reset the row variable
								row = d_bound.i_list_start_row;

								// Print every visible session from top
								for(unsigned long i = l_track.ul_current_topmost_session; i < vl_sessionList.size(); i++){
									// If item is visible, print it
									if(vl_sessionList[i].b_visible){
										printSession(row++, i, d_colors.str_default_color);
									}
									// Break if we hit bottom
									if(row >= d_bound.i_list_end_row)
										break;
								}
								// Highlight the last line in the list
								printSession(d_bound.i_list_end_row, 0, d_colors.str_list_highlighted_color);

								// Update tracking for current highlighted session
								l_track.ul_current_highlighted_session++;

								return;
							} // if(l_track.ul_current_highlighted_row == d_bound.i_list_end_row)
	} // switch(_direction)
	return;
}
