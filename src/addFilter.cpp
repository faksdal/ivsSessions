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
								int			_fieldLength,
								bool		_active,
								std::string	_filterName,
								std::string	_filterText,
								std::string	_filterColor,
								FilterTypes _ft)
{
	vl_filter.push_back({	_filterColumn,
							_filterRow,
							_fieldLength,
							_active,
							_filterName,
							_filterText,
							_filterColor,
							_ft });
}
