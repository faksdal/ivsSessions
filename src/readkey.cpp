/*
 * readkey.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <unistd.h>
#include <iostream>
#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
int ivsSessions::readkey(int _fd)
{

	int nread;
	char c;


	while ((nread = read(_fd, &c, 1)) != 1){
		if (nread == -1 && errno != EAGAIN)
			exit(-1);
	} // while ((nread = read(STDIN_FILENO, &c, 1)) != 1)

	if (c == '\x1b'){
		char seq[3];

		if (read(_fd, &seq[0], 1) != 1) return '\x1b';
		if (read(_fd, &seq[1], 1) != 1) return '\x1b';

		if (seq[0] == '['){
			if (seq[1] >= '0' && seq[1] <= '9'){
				if (read(_fd, &seq[2], 1) != 1) return '\x1b';
			if (seq[2] == '~'){
				switch(seq[1]){
					case '1': return HOME;
					case '3': return DELETE;
					case '4': return END;
					case '5': return PAGE_UP;
					case '6': return PAGE_DOWN;
					case '7': return HOME;
					case '8': return END;
				} // switch(seq[1])
			}
			}
			else{
				switch(seq[1]){
					case 'A': return UP_ARROW;
					case 'B': return DOWN_ARROW;
					case 'C': return RIGHT_ARROW;
					case 'D': return LEFT_ARROW;
					case 'H': return HOME;
					case 'F': return END;
				} // switch(seq[1])
			}
	    } // if (seq[0] == '[')
		else if(seq[0] == 'O'){
			switch(seq[1]){
				case 'H': return HOME;
				case 'F': return END;
			}
		}
		return '\x1b';
	} // if (c == '\x1b')
	else{
		return c;
	}


	  /*
	int			seqCnt = 0, retkey = -1;
	keyState	state;
	char		c = '\0';
	char		seq[4];


	if(read(_fd, &c, 1) == 1){
		//std::cout << "key: " << (int)c << std::endl;
		state = keyState::NORMAL;
		// If we encounter an escape sequence, we start populate the seq[]
		// and set the appropriate state value
		if(c == 27){
			// If we have indications of an escape sequence, we try another
			// read()
			state = keyState::ESCAPE_SEQ_0;
			if(read(_fd, &seq[seqCnt], 1) > 0){
				seqCnt++;
				state = keyState::ESCAPE_SEQ_1;
				if(read(_fd, &seq[seqCnt], 1) > 0){
					seqCnt++;
					state = keyState::ESCAPE_SEQ_2;
					if(read(_fd, &seq[seqCnt], 1) > 0){
						seqCnt++;
						state = keyState::ESCAPE_SEQ_3;
						if(read(_fd, &seq[seqCnt], 1) > 0){
							state = keyState::ESCAPE_SEQ_4;
						}
					}
				}
			}

		} // if(c = 27)
		switch(state){
			case keyState::NORMAL:			retkey = c;
											break;
			case keyState::ESCAPE_SEQ_0:	retkey = ESC;
											break;
			case keyState::ESCAPE_SEQ_1:	break;
			case keyState::ESCAPE_SEQ_2:	switch(seq[1]){
												case 65:	retkey = UP_ARROW;
															break;
												case 66:	retkey = DOWN_ARROW;
															break;
												case 67:	retkey = RIGHT_ARROW;
															break;
												case 68:	retkey = LEFT_ARROW;
															break;
												case 80:	retkey = F1;
															break;
												case 81:	retkey = F2;
															break;
												case 82:	retkey = F3;
															break;
												case 83:	retkey = F4;
															break;
											}
											break;
			case keyState::ESCAPE_SEQ_3:	switch(seq[1]){
												case 49:	retkey = HOME;
															break;
												case 50:	retkey = INSERT;
															break;
												case 51:	retkey = DELETE;
															break;
												case 52:	retkey = END;
															break;
												case 53:	retkey = PAGE_UP;
															break;
												case 54:	retkey = PAGE_DOWN;
															break;
											}
											break;
			case keyState::ESCAPE_SEQ_4:	switch(seq[2]){
												case 48:	retkey = F9;
															break;
												case 49:	retkey = F10;
															break;
												case 51:	retkey = F11;
															break;
												case 52:	retkey = F12;
															break;
												case 53:	retkey = F5;
															break;
												case 55:	retkey = F6;
															break;
												case 56:	retkey = F7;
															break;
												case 57:	retkey = F8;
															break;
											}
											break;
			default:						break;
		}
	} // if(read(_fd, &c, 1) == 1)

	return retkey;
	*/

}
