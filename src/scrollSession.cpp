/*
 * scrollSession.cpp
 *
 *  Created on: 9 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"
	/*
	enum ScrollState {	TOP,
						BOTTOM,
						MOVE_UP,
						MOVE_DOWN,
						SCROLL_UP,
						SCROLL_DOWN
	};
	*/
////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::scrollSession(int _key)
{
	ScrollState	scrollState;

	switch(scrollState = getScrollState(_key)){
		case ScrollState::TOP:		break;
	} // switch(scrollState = getScrollState(_key))
}
