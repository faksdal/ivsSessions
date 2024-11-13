/*
 * getFirstVisibleIndex.cpp
 *
 *  Created on: Nov 13, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"
unsigned long ivsSessions::getFirstVisibleIndex(void)
{
	for(unsigned long i = 0; i < vl_sessionList.size(); i++){
		if(vl_sessionList[i].b_visible)
			return i;
	}
	return (vl_sessionList.size() + 1);
}
