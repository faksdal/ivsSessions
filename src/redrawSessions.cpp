/*
 * redrawList.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

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

	//			There are three situations we can encounter:
	//
	//	1 -	The highlighted item are between the boundaries, and we just need
	//		to move the highlighted area on screen. This does not involve
	//		scrolling of the list.
	//
	//	2 -	We are at either lower or upper screen boundary, and need to
	//		scroll the list. This calls for redrawing of the whole screen.
	//
	//	3 -	We are at the top or bottom and at the same time at the beginning
	//		or end of the list; then we don't do anything.

	// I guess it makes sense to check for #3 first. If either of the
	// conditions are present, we just return.
	//	if( current list item == 0 (top) || current list item == list.size()-1 (bottom)){
	//		return;
	//	}



	// Let's start by scanning the whole list
	for(unsigned long i = 0; i < vl_sessionList.size(); i++){

		// If item is visible, print it
		if(vl_sessionList[i].b_visible){

		}

	}
}
