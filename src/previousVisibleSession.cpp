/*
 * previousVisibleSession.cpp
 *
 *  Created on: Nov 8, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"



unsigned long ivsSessions::previousVisibleSession(unsigned long _startItem)
{
	if(_startItem > 0){
		for(unsigned long i = _startItem - 1; i >= 0 ; i--){
			if(vl_sessionList[i].b_visible)
				return(i);
			if(i == 0)
				return(_startItem);
		} // for(unsigned long i = _startItem - 1; i >= 0 ; i--)
	} // if(_startItem > 0)
	return(_startItem);
}
