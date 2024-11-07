/*
 * restoreTerminalState.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <unistd.h>
#include "ivsSessions.h"



void ivsSessions::restoreTerminalState(void)
{
	// Restore the saved terminal settings
	if (tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios) == -1){
		errorMessage("ivsSessions::restoreTerminalState()", "Failed to restore terminal attributes");
		//perror("Failed to restore terminal attributes");
		//exit(EXIT_FAILURE);
	}
}
