/*
 * printFilteredSession.cpp
 *
 *  Created on: Nov 19, 2024
 *      Author: leijon
 */

#include <string>

#include "ivsSessions.h"



void ivsSessions::printFilteredSession(short _row, unsigned long _sessionId, std::string _sessionColor, FilterTypes _ft)
{
	std::string	f_string;
	size_t		highlightIndex;


	switch(vl_filter[getActiveFilterIndex()].ft){

		case FilterTypes::SESSION_TYPE:		f_string = vl_sessionList[_sessionId].str_sessionType;
											highlightIndex = f_string.find(vl_filter[getActiveFilterIndex()].str_filterText);
											if(highlightIndex != std::string::npos){
												//f_string.insert(highlightIndex, d_colors.str_list_highlighted_color);
												f_string.insert(highlightIndex, "\033[30;102m");

												//f_string.insert(highlightIndex + 14, _sessionColor);
												f_string.insert(highlightIndex + 9 + vl_filter[getActiveFilterIndex()].str_filterText.length(), "\033[40;00m");
												print(1, d_bound.i_list_end_row + 1, f_string.c_str());
											}

											print(1, _row,	_sessionColor
															+	f_string
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
											break;
		case FilterTypes::DATE:				f_string = vl_sessionList[_sessionId].str_date;
											print(1, _row,	_sessionColor
															+	vl_sessionList[_sessionId].str_sessionType
															+	f_string
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
											break;
		case FilterTypes::SESSION_CODE:		f_string = vl_sessionList[_sessionId].str_sessionCode;
											print(1, _row,	_sessionColor
															+	vl_sessionList[_sessionId].str_sessionType
															+	vl_sessionList[_sessionId].str_date
															+	f_string
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
											break;
		case FilterTypes::STATIONS:			f_string = vl_sessionList[_sessionId].str_stations;
											print(1, _row,	_sessionColor
															+	vl_sessionList[_sessionId].str_sessionType
															+	vl_sessionList[_sessionId].str_date
															+	vl_sessionList[_sessionId].str_sessionCode
															+	vl_sessionList[_sessionId].str_doy
															+	vl_sessionList[_sessionId].str_time
															+	vl_sessionList[_sessionId].str_dur
															+	f_string
															+	vl_sessionList[_sessionId].str_sked
															+	vl_sessionList[_sessionId].str_corr
															+	vl_sessionList[_sessionId].str_status
															+	vl_sessionList[_sessionId].str_dbcCode
															+	vl_sessionList[_sessionId].str_subm
															+	vl_sessionList[_sessionId].str_del);
											break;

	} // switch(vl_filter[getActiveFilterIndex()].ft)
}
