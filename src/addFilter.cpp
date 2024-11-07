/*
 * addFilter.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Add filter to the list
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::addFilter(	int			_filterColumn,
								int			_filterRow,
								bool		_active,
								std::string	_filterName,
								std::string	_filterText,
								std::string	_filterColor)
{
	vl_filter.push_back({	_filterColumn,
							_filterRow,
							_active,
							_filterName,
							_filterText,
							_filterColor });

	//unsigned long i = 0;

	//while(!filter[i++].active);
	//i--;

	//print(1, 33, "         ");
	//print(1, 33, i);

	//filter[i].filterText.append(1, _key);

	//print(1, 34, "         ");
	//print(1, 34, filter[i].filterName);
	//print(1, 35, "         ");
	//print(1, 35, filter[i].filterText);

	//kb.moveCursor(kb.cursorColumn, kb.cursorRow);
}
