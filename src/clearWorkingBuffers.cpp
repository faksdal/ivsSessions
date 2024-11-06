/*
 * clearWorkingBuffers.cpp
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
void ivsSessions::clearWorkingBuffers(void)
{
	str_buffer.clear();
	str_sessionType.clear();
	str_date.clear();
	str_sessionCode.clear();
	str_doy.clear();
	str_time.clear();
	str_dur.clear();
	str_stations.clear();
	str_sked.clear();
	str_corr.clear();
	str_status.clear();
	str_dbcCode.clear();
	str_subm.clear();
	str_del.clear();

	b_visible		= false;
	b_highlighted	= false;
}
