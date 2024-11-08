/*
 * addListItem.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::addListItem(void)
{

	//std::cout << d_colors.str_default_color + "\r\nAdding an item to the list.\r\n" << std::flush;

	// Add the current line to the list
	vl_sessionList.push_back({	str_sessionType,
								str_date,
								str_sessionCode,
								str_doy,
								str_time,
								str_dur,
								str_stations,
								str_sked,
								str_corr,
								str_status,
								str_dbcCode,
								str_subm,
								str_del,
								true,
								false });
}
