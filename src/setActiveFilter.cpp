/*
 * setActiveFilter.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//	Places the cursor in the active filter, and displays it
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::setFocusActiveFilter(void)
{
	int i = 0;

	while(!vl_filter[i++].b_active);
	i--;

	moveCursor(vl_filter[i].i_filterColumn, vl_filter[i].i_filterRow);

	// Update cursor location
	c_where.i_column	= vl_filter[i].i_filterColumn;
	c_where.i_row		= vl_filter[i].i_filterRow;

	showCursor();
}
