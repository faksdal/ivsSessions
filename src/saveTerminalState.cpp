/*
 * saveTerminalState.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <unistd.h>
#include "ivsSessions.h"



void ivsSessions::saveTerminalState(void)
{
	// Save the current terminal settings
	if (tcgetattr(STDIN_FILENO, &originalTermios) == -1){
		errorMessage("ivsSessions::saveTerminalState()", "Failed to get terminal attributes");
		//perror("Failed to get terminal attributes");
		//exit(EXIT_FAILURE);
	}
}
