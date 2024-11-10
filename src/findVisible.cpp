/*
 * findVisible.cpp
 *
 *  Created on: 9 Nov 2024
 *      Author: jole
 */
#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
bool ivsSessions::findVisible(	unsigned long _startSession,
								unsigned long& _nextSession,
								int _direction)
{

	switch(_direction){
		case UP_ARROW:		// We search back in the sessionList looking for
							// the first, previous visible session
							for(unsigned long i = _startSession - 1; i >= 0 ; i--){

								// If we find a visible session, we return with
								// the result
								if(vl_sessionList[i].b_visible){
									_nextSession = i;
									return true;
								} // if(vl_sessionList[i].b_visible)

								// If we hit the first session without finding
								// a visible one, there are no more visible and
								// we simply return the _startSession
								if(i == 0){
									_nextSession = _startSession;
									return false;
								} // if(i == 0)

							} // for(unsigned long i = _startSession - 1; i >= 0 ; i--)
							//break;

		case DOWN_ARROW:	// We search forward in the sessionList looking for
							// the next visible session
							for(unsigned long i = _startSession + 1; i < vl_sessionList.size()/* - 1*/; i++){
								if(vl_sessionList[i].b_visible){
									_nextSession = i;
									return true;
								} // if(vl_sessionList[i].b_visible)
							} // for(unsigned long i = _startSession + 1; i < vl_sessionList.size()/* - 1*/; i++)
							_nextSession = _startSession;
							return false;

		default:			return false;
	}//switch(_direction)
}
