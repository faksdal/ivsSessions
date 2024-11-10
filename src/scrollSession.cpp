/*
 * scrollSession.cpp
 *
 *  Created on: 9 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"
////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::scrollSession(int _key)
{
	ScrollState	scrollState;

	switch(scrollState = getScrollState(_key)){
		case ScrollState::TOP:				break;
		case ScrollState::BOTTOM:			break;
		case ScrollState::MOVE_UP:			break;
		case ScrollState::MOVE_DOWN:		break;
		case ScrollState::SCROLL_UP:		break;
		case ScrollState::SCROLL_DOWN:		break;
	} // switch(scrollState = getScrollState(_key))
}
