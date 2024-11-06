/*
 * errorMessage.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
//
// ivsSessions::errorMessage prints an errormessage to stderr, and exits
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::errorMessage(const std::string _callerId, const std::string _message)
{
	std::cerr << _callerId << " reported an error. " << _message << "\r\n" << std::flush;
	std::cerr << "Exiting... \r\n" << std::flush;
	exit(0);
}
