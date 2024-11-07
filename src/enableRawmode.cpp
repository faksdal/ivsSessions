/*
 * enableRawmode.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

//#include <cstdlib>
//#include <iostream>
//#include <stdlib.h>
//#include "keyboard.h"
#include <unistd.h>
#include "ivsSessions.h"



void ivsSessions::enableRawmode(void)
{
	struct termios raw = originalTermios;


	tcgetattr(STDOUT_FILENO, &originalTermios);

	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	//raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); // I want ISIG on
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	raw.c_cc[VMIN] = 0;
	raw.c_cc[VTIME] = 1;
	tcsetattr(STDOUT_FILENO, TCSAFLUSH, &raw);

	//std::cout << "\r\nkeyboard::enableRawMode\r\n" << std::flush;
}
