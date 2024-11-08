/*
 * nextVisibleSession.cpp
 *
 *  Created on: Nov 8, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Scanning session list for next visible item. If none, return _startItem
////////////////////////////////////////////////////////////////////////////////
unsigned long ivsSessions::nextVisibleSession(unsigned long _startItem)
{
	for(unsigned long i = _startItem + 1; i < vl_sessionList.size()/* - 1*/; i++){
		if(vl_sessionList[i].b_visible)
			return(i);
	}

	return(_startItem);
}
