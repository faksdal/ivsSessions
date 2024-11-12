/*
 * applyFilter.cpp
 *
 *  Created on: Nov 12, 2024
 *      Author: leijon
 */
//#pragma GCC diagnostic ignored "-Wsign-compare" (i < d_bound.i_list_end_row)

#include "ivsSessions.h"



void ivsSessions::applyFilter(void)
{
	unsigned long row = d_bound.i_list_start_row;

	// Clear the sessionlist from the screen
	for(unsigned long i = 0; i < d_bound.i_list_end_row; i++){
		print(0, row++, d_colors.str_default_color + "                                                                                                                                             ");
	}


	for(unsigned long i = 0; i < vl_sessionList.size(); i++){

		switch(vl_filter[getActiveFilterIndex()].ft){

			case FilterTypes::SESSION_TYPE:		if(vl_sessionList[i].str_sessionType.find(vl_filter[getActiveFilterIndex()].str_filterText) == std::string::npos)
													vl_filter[getActiveFilterIndex()].str_filterText)
												break;
			case FilterTypes::DATE:				//
												break;
			case FilterTypes::SESSION_CODE:		//
												break;
			case FilterTypes::STATIONS:			//
												break;

		} // switch(vl_filter[getActiveFilterIndex()].ft)

	} // for(unsigned long i = 0; i < vl_sessionList.size(); i++)

	//printSession(d_bound.i_list_start_row, 0, d_colors.str_list_highlighted_color);
	//updateListTracking(0, 0, d_bound.i_list_start_row);
}
