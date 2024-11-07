/*
 * disableRawmode.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <unistd.h>
#include "ivsSessions.h"



void ivsSessions::disableRawmode(void)
{
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &originalTermios);
}
