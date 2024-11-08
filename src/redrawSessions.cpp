/*
 * redrawList.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

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
	int row;

	// First case is _key == 0; indicating this is the initial print of
	// the list. All items will be visible, we just need to print them, and
	// update the tracking variables.
	if(_key == 0){
		row = d_bound.i_list_start_row;
		for(unsigned long i = 0; i < vl_sessionList.size(); i++){
			// If item is visible, print it
			if(vl_sessionList[i].b_visible){
				printSession(row++, i, d_colors.str_default_color);
			}
			if(row >= d_bound.i_list_end_row)
				break;
		}
		// Highlight the first line in the list
		printSession(d_bound.i_list_start_row, 0, d_colors.str_list_highlighted_color);
		updateListTracking(0, 0);

		return;
	} // if(_key == 0)



	// Next case is if the user has pressed UP_ARROW
	else if(_key == UP_ARROW){
		return;
	} // else if(_key == UP_ARROW)



	// Third case is if the user has pressed DOWN_ARROW
	else if(_key == DOWN_ARROW){
		return;
	} // else if(_key == DOWN_ARROW)
}
