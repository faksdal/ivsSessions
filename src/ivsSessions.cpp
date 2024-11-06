/*
 * ivsSessions.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// Class constructor
//
////////////////////////////////////////////////////////////////////////////////
ivsSessions::ivsSessions(std::string _inputFileName)
{
	str_inputFileName = _inputFileName;

	if(!fileExists(str_inputFileName))
		errorMessage("Constructor", " Inputfile does not exists: " + str_inputFileName);

	d_bound.s_header1_row = 1;
	d_bound.s_header2_row = 2;
	d_colors.str_headerColor = "\033[40;00m";
}



////////////////////////////////////////////////////////////////////////////////
//
// Class destructor
//
////////////////////////////////////////////////////////////////////////////////
ivsSessions::~ivsSessions()
{

}
