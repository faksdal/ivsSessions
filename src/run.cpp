/*
 * run.cpp
 *
 *  Created on: 6 Nov 2024
 *      Author: jole
 */

#include <iostream>
#include "ivsSessions.h"

////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
int ivsSessions::run(void)
{
	// Call readFile to read inputfile and populate str_inputBuffer.
	readFile();

	// Parse the input buffer, and populate sessions list
	parser();

	printHeaders();

	return(0);
}
