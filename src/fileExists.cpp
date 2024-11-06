/*
 * fileexists.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <sys/stat.h>
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
// ivsSessions::fileexists checks if _filename exist
//
// It returns true or false based on the existence of _filename
//
////////////////////////////////////////////////////////////////////////////////
bool ivsSessions::fileExists(const std::string _filename)
{
	struct stat buffer;

	return(stat(_filename.c_str(), &buffer) == 0);
}
