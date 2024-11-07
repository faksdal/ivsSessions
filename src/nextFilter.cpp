/*
 * nextFilter.cpp
 *
 *  Created on: 7 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
// Cycling through filters, moving focus to the next one...
// Updating cursor location at the same time.
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::nextFilter(void)
{

	unsigned long i;

	for(i = 0; i < vl_filter.size(); i++){
		if(vl_filter[i].b_active){
			vl_filter[i].b_active = false;
			if(i+1 == vl_filter.size()){
				i = 0;
				vl_filter[i].b_active = true;
				break;
			}
			else{
				i++;
				vl_filter[i].b_active = true;
				break;
			}
		}
	}
	setFocusActiveFilter();

	/*
	kb.cursorColumn	=  filter[i].filterColumn;
	kb.cursorRow	=  filter[i].filterRow;
	kb.moveCursor(kb.cursorColumn, kb.cursorRow);
	*/
}
