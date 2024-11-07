/*
 * getActiveFilterIndex.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
// Returns index of the active filter
////////////////////////////////////////////////////////////////////////////////
int ivsSessions::getActiveFilterIndex(void)
{
	int i = 0;

	while(!vl_filter[i++].b_active);
	i--;

	return(i);
}
