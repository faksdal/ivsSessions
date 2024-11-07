/*
 * setupFilters.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Prepares the filter list
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::setupFilters(void)
{
	addFilter(	2,
				d_bound.i_filter_row,
				12,
				true,
				"SESSION_TYPE",
				"",
				d_colors.str_filter_passive_color);

	addFilter(	15,
				d_bound.i_filter_row,
				8,
				false,
				"DATE",
				"",
				d_colors.str_filter_passive_color);

	addFilter(	24,
				d_bound.i_filter_row,
				12,
				false,
				"SESSION_CODE",
				"",
				d_colors.str_filter_passive_color);

	addFilter(	53,
				d_bound.i_filter_row,
				12,
				false,
				"STATIONS",
				"",
				d_colors.str_filter_passive_color);

	for(unsigned long i = 0; i < vl_filter.size(); i++){
		print(		vl_filter[i].i_filterColumn,
					vl_filter[i].i_filterRow,
					vl_filter[i].str_filterColor + vl_filter[i].str_filterText);
	}

	//setFocusActiveFilter();

}
