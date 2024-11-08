/*
 * updateListTracking.cpp
 *
 *  Created on: Nov 8, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//	Updates content of:
//		class listTracking{
//		public:
//			unsigned long	ul_current_highlighted_session,
//							ul_current_topmost_session;
//		};
//
//	listTracking		l_track;
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::updateListTracking(	unsigned int _current_highlighted_session,
										unsigned int _current_topmost_session,
										unsigned int _current_highlighted_row)
{
	l_track.ul_current_highlighted_session	= _current_highlighted_session;
	l_track.ul_current_topmost_session		= _current_topmost_session;
	l_track.ul_current_highlighted_row		= _current_highlighted_row;
}
