/*
 * applyFilter.cpp
 *
 *  Created on: Nov 12, 2024
 *      Author: leijon
 */
#pragma GCC diagnostic ignored "-Wsign-compare" (i < d_bound.i_list_end_row)

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

			case FilterTypes::SESSION_TYPE:		if(vl_sessionList[i].str_sessionType.find(vl_filter[getActiveFilterIndex()].str_filterText) == std::string::npos){
													vl_sessionList[i].b_visible = false;
												}
												break;
			case FilterTypes::DATE:				if(vl_sessionList[i].str_date.find(vl_filter[getActiveFilterIndex()].str_filterText) == std::string::npos){
													vl_sessionList[i].b_visible = false;
												}
												break;
			case FilterTypes::SESSION_CODE:		if(vl_sessionList[i].str_sessionCode.find(vl_filter[getActiveFilterIndex()].str_filterText) == std::string::npos){
													vl_sessionList[i].b_visible = false;
												}
												break;
			case FilterTypes::STATIONS:			if(vl_sessionList[i].str_stations.find(vl_filter[getActiveFilterIndex()].str_filterText) == std::string::npos){
													vl_sessionList[i].b_visible = false;
												}
												break;

		} // switch(vl_filter[getActiveFilterIndex()].ft)

	} // for(unsigned long i = 0; i < vl_sessionList.size(); i++)

	row = d_bound.i_list_start_row;
	for(unsigned long i = 0; i < vl_sessionList.size(); i++){

		// If item is visible, print it
		if(vl_sessionList[i].b_visible){
			printSession(row++, i, d_colors.str_default_color);
		} // if(vl_sessionList[i].b_visible)

		if(row > d_bound.i_list_end_row)
			break;
	} // for(unsigned long i = 0; i < vl_sessionList.size(); i++)

	printSession(d_bound.i_list_start_row, getFirstVisibleIndex(), d_colors.str_list_highlighted_color);
	updateListTracking(getFirstVisibleIndex(), getFirstVisibleIndex(), d_bound.i_list_start_row);
}
