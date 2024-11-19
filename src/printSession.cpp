/*
 * printSession.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <string>

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
// Prints a single session, _sessionId, at row _row, using _sessionColor
// Calls function print() to do the actual printing.
// Function print() is responsible for turning the cursor off during printing, and
// back on after it's done.
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printSession(short _row, unsigned long _sessionId, std::string _sessionColor)
{
	print(1, _row,	_sessionColor
				+	vl_sessionList[_sessionId].str_sessionType
				+	vl_sessionList[_sessionId].str_date
				+	vl_sessionList[_sessionId].str_sessionCode
				+	vl_sessionList[_sessionId].str_doy
				+	vl_sessionList[_sessionId].str_time
				+	vl_sessionList[_sessionId].str_dur
				+	vl_sessionList[_sessionId].str_stations
				+	vl_sessionList[_sessionId].str_sked
				+	vl_sessionList[_sessionId].str_corr
				+	vl_sessionList[_sessionId].str_status
				+	vl_sessionList[_sessionId].str_dbcCode
				+	vl_sessionList[_sessionId].str_subm
				+	vl_sessionList[_sessionId].str_del);
}



