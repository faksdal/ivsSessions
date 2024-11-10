/*
 * visibleSessions.cpp
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
unsigned long ivsSessions::visibleSessions(void)
{
	unsigned long retval = 0;

	for(unsigned long i = 0; i < vl_sessionList.size(); i++){
		if(vl_sessionList[i].b_visible)
			retval++;
	}
	return retval;
}
