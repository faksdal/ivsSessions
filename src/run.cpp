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

	// Sets up display for use
	setupDisplay();

	printHeaders();

	std::cout << "\r\n\r\n columns x rows: " << d_bound.i_total_columns << " x " << d_bound.i_total_rows << "\r\n" << std::flush;

	restoreTerminalState();

	return(0);
}
