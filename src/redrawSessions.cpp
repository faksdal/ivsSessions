/*
 * redrawList.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */
#pragma GCC diagnostic ignored "-Wsign-compare" (d_bound.i_list_end_row > l_track.ul_current_highlighted_row)

#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// What do I need to re-draw the session list?
//
// What do I want from this function?
//		* I want to be able to call it from anywhere
//		* I want it to draw all visible items to the visible portion of screen
//		* I want it to stop printing when it either; reaches the bottom of the
//			screen, or when we are at the last session in the list
//		* When scrolling, I want it to take into account which item is first,
// 			which item is highlighted, and when to stop printing
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::redrawSessions(int _key)
{
	int				row;
	unsigned long	nextVisible;
	unsigned long	previousVisible;


	switch(_key){
		case 0:				// First case is _key == 0; indicating this is the initial print of
							// the list. All items will be visible, we just need to print them, and
							// update the tracking variables.
							row = d_bound.i_list_start_row;
							for(unsigned long i = 0; i < vl_sessionList.size(); i++){
								// If item is visible, print it
								if(vl_sessionList[i].b_visible){
									printSession(row++, i, d_colors.str_default_color);
								} // if(vl_sessionList[i].b_visible)

								if(row > d_bound.i_list_end_row)
									break;
							} // for(unsigned long i = 0; i < vl_sessionList.size(); i++)

							// Highlight the first line in the list, and update the list tracking
							printSession(d_bound.i_list_start_row, 0, d_colors.str_list_highlighted_color);
							updateListTracking(0, 0, d_bound.i_list_start_row);
							return;

		case UP_ARROW:		// Search for previous visible list item, if any...
							previousVisible = previousVisibleSession(l_track.ul_current_highlighted_session);

							// If previousVisible equals the currently highlighted one, it means
							// we're at the top of the list. Nothing should be done.
							if(previousVisible == l_track.ul_current_highlighted_session){
								return;
							}

							// Check if we're at the top of the screen...
							if(l_track.ul_current_highlighted_row == d_bound.i_list_start_row){
								// ...and if we are, we re-draw the whole list.
								scrollSessionList(UP_ARROW, 1);
								return;
							} // if(l_track.ul_current_highlighted_row == d_bound.i_list_start_row)


							// If we're not at the top of the screen, we should just move the
							// highlighted bar one row up.

							// If we found a previous visible...
							if(l_track.ul_current_highlighted_session > previousVisible){
								// Overwrite the current with default color
								printSession(	l_track.ul_current_highlighted_row,
												l_track.ul_current_highlighted_session,
												d_colors.str_default_color);

								// Update tracking
								l_track.ul_current_highlighted_row--;
								l_track.ul_current_highlighted_session = previousVisible;

								// Print the previous one in highlighted colors
								printSession(	l_track.ul_current_highlighted_row,
												l_track.ul_current_highlighted_session,
												d_colors.str_list_highlighted_color);

							} // if(l_track.ul_current_highlighted_session > previousVisible)
							return;

		case DOWN_ARROW:	// Search for next visible list item, if any...
							nextVisible = nextVisibleSession(l_track.ul_current_highlighted_session);
							// If nextVisible is the same as the currently highlighted one. it means
							// there are no more items to show...
							if(nextVisible == l_track.ul_current_highlighted_session)
								return;

							// Continuing down here, means there are more sessions to be shown

							// If we are at the bottom of the screen, we must check to see if
							// there are more sessions to be shown, and thus scroll the list.
							// However, should we be at the bottom, AND the last visible session
							// is shown - we do nothing

							// Check if we're at the bottom of the screen...
							if(l_track.ul_current_highlighted_row == d_bound.i_list_end_row){
								scrollSessionList(DOWN_ARROW, 1);
								return;
							} // if(l_track.ul_current_highlighted_row == d_bound.i_list_end_row)

							// If we are not at the bottom of the screen, it's just a matter of
							// moving the highlighted section one row downward

							// Search for next visible list item, if any...
							//nextVisible = nextVisibleSession(l_track.ul_current_highlighted_session);

							// If we found a next visible...
							if(nextVisible > l_track.ul_current_highlighted_session){

								// Overwrite the current with default color
								printSession(	l_track.ul_current_highlighted_row,
												l_track.ul_current_highlighted_session,
												d_colors.str_default_color);

								// Update tracking
								l_track.ul_current_highlighted_row++;
								l_track.ul_current_highlighted_session = nextVisible;

								// Print the next one in highlighted colors
								printSession(	l_track.ul_current_highlighted_row,
												l_track.ul_current_highlighted_session,
												d_colors.str_list_highlighted_color);
							} // if(nextVisible > l_track.ul_current_highlighted_session)
							return;


	} // switch(_key)
}
