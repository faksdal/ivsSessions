/*
 * parser.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

// disable warning for unused value
#pragma GCC diagnostic ignored "-Wunused-value" *chr_ptr

#include <iostream>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Parsing the input buffer with the help of a state machine.
// Learning and inspiration from:
//		* https://www.youtube.com/watch?v=rauO5qespFc&t=1077s
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::parser(void)
{

	state	= State::READY;

	// Pointer to inputbuffer from file
	chr_ptr	= str_inputBuffer.c_str();

	clearWorkingBuffers();

	while(*chr_ptr){
		switch(state){
		case State::READY:			switch(*chr_ptr){
										case '#':	state = State::FILE_FORMAT;
													break;
										case '|':	state = State::SESSION_TYPE;
													str_sessionType.append(1, *chr_ptr);
													*chr_ptr++;
													//fo_inputBufferIndex++;
													break;
										case '\r':	*chr_ptr++;
													break;
										case '\n':	*chr_ptr++;
													break;
										case ' ':	state = State::NEW_LINE;
													break;
										case '-':	*chr_ptr++;
													//fo_inputBufferIndex++;
													//state = State::HORIZONTAL_DIVIDER;
													break;
										default:	break;
									}
									break;
		case State::NEW_LINE:		if(*chr_ptr == '\r'){
										str_buffer.append(1, '\0');
										*chr_ptr++;
										//fo_inputBufferIndex++;
										state = State::CHECK_NEW_LINE;
										break;
									}
									str_buffer.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::CHECK_NEW_LINE: if(str_buffer.find("MULTI-AGENCY SCHEDULE") != std::string::npos){
										b_intensiveFlag = false;
									}
									else if(str_buffer.find("MULTI-AGENCY INTENSIVE SCHEDULE") != std::string::npos){
										b_intensiveFlag = true;
									}
									else if(str_buffer.find("SESSION") != std::string::npos){
										str_header1 = str_buffer;
									}
									else if(str_buffer.find("TYPE") != std::string::npos){
										str_header2 = str_buffer;
									}
									str_buffer.clear();
									state = State::READY;
									break;
		case State::FILE_FORMAT:	if(*chr_ptr == '\r'){
										str_fileFormat.append(1, '\0');
										state = State::READY;
										*chr_ptr++;
										//fo_inputBufferIndex++;
										break;
									}
									str_fileFormat.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SESSION_TYPE:	if(*chr_ptr == '|'){
										str_sessionType.append(1, '\0');
										state = State::DATE;
										break;
									}
									str_sessionType.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DATE:			if(*chr_ptr == '|'){
										if(str_date.size() < 1){
											str_date.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_date.append(1, '\0');
										state = State::SESSION_CODE;
										break;
									}
									str_date.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SESSION_CODE:	if(*chr_ptr == '|'){
										if(str_sessionCode.size() < 1){
											str_sessionCode.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_sessionCode.append(1, '\0');
										state = State::DOY;
										break;
									}
									str_sessionCode.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DOY:			if(*chr_ptr == '|'){
										if(str_doy.size() < 1){
											str_doy.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_doy.append(1, '\0');
										state = State::TIME;
										break;
									}
									str_doy.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::TIME:			if(*chr_ptr == '|'){
										if(str_time.size() < 1){
											str_time.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_time.append(1, '\0');
										state = State::DUR;
										break;
									}
									str_time.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DUR:			if(*chr_ptr == '|'){
										if(str_dur.size() < 1){
											str_dur.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_dur.append(1, '\0');
										state = State::STATIONS;
										break;
									}
									str_dur.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::STATIONS:		if(*chr_ptr == '|'){
										if(str_stations.size() < 1){
											str_stations.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_stations.append(1, '\0');
										state = State::SKED;
										break;
									}
									str_stations.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SKED:			if(*chr_ptr == '|'){
										if(str_sked.size() < 1){
											str_sked.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_sked.append(1, '\0');
										state = State::CORR;
										break;
									}
									str_sked.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::CORR:			if(*chr_ptr == '|'){
										if(str_corr.size() < 1){
											str_corr.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_corr.append(1, '\0');
										state = State::STATUS;
										break;
									}
									str_corr.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::STATUS:			if(*chr_ptr == '|'){
										if(str_status.size() < 1){
											str_status.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_status.append(1, '\0');
										state = State::DBC_CODE;
										break;
									}
									str_status.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::DBC_CODE:		if(*chr_ptr == '|'){
										if(str_dbcCode.size() < 1){
											str_dbcCode.append(1, *chr_ptr);
											*chr_ptr++;
											//fo_inputBufferIndex++;
											break;
										}
										str_dbcCode.append(1, '\0');
										state = State::SUBM;
										break;
									}
									str_dbcCode.append(1, *chr_ptr);
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
		case State::SUBM:		if(*chr_ptr == '|'){
									if(str_subm.size() < 1){
										str_subm.append(1, *chr_ptr);
										*chr_ptr++;
										//fo_inputBufferIndex++;
										break;
									}
									str_subm.append(1, '\0');
									state = State::DEL;
									break;
								}
								str_subm.append(1, *chr_ptr);
								*chr_ptr++;
								//fo_inputBufferIndex++;
								break;
		case State::DEL:		if(*chr_ptr == '|'){
									if(str_del.size() < 1){
										str_del.append(1, *chr_ptr);
										*chr_ptr++;
										//fo_inputBufferIndex++;
										break;
									}
									str_del.append(1, *chr_ptr);
									str_del.append(1, '\0');
									state = State::ADD_LIST_ITEM;
									*chr_ptr++;
									//fo_inputBufferIndex++;
									break;
								}
								str_del.append(1, *chr_ptr);
								*chr_ptr++;
								//fo_inputBufferIndex++;
								break;

		case State::ADD_LIST_ITEM:	addListItem();
									clearWorkingBuffers();
									state = State::READY;
									break;
			default:			break;
		}
	}

	// Initialize the list with the first item to be highlighted
	vl_sessionList[0].b_highlighted = true;

}
