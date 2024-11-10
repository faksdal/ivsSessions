/*
 * getScrollState.cpp
 *
 *  Created on: 9 Nov 2024
 *      Author: jole
 */

#include "keymap.h"
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
ivsSessions::ScrollState ivsSessions::getScrollState(int _key)
{
	ScrollState		retval;
	unsigned long	nextVisibleSession;

	switch(_key){
	case UP_ARROW:		// Search for previous visible list item, if any...
						if(!findVisible(l_track.ul_current_highlighted_session, nextVisibleSession, _key))
							retval = ScrollState::TOP;
						break;

	case DOWN_ARROW:	break;
	case PAGE_UP:		break;
	case PAGE_DOWN:		break;
	case HOME:			break;
	case END:			break;
	}//switch(_key)

	return retval;
}
