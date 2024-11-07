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
	/*
	unsigned long i;

	for(i = 0; i < filter.size(); i++){
		if(filter[i].active){
			filter[i].active = false;
			if(i+1 == filter.size()){
				i = 0;
				filter[i].active = true;
				break;
			}
			else{
				i++;
				filter[i].active = true;
				break;
			}
		}
	}

	kb.cursorColumn	=  filter[i].filterColumn;
	kb.cursorRow	=  filter[i].filterRow;
	kb.moveCursor(kb.cursorColumn, kb.cursorRow);
	*/
}
