/*
 * keyboard.h
 *
 *  Created on: 2 Nov 2024
 *      Author: jole
 */
#pragma once

//#include <unistd.h>
#include <termios.h>

#include "keymap.h"



class keyboard{

	enum keyState{	NORMAL,
					ESCAPE_SEQ_0,
					ESCAPE_SEQ_1,
					ESCAPE_SEQ_2,
					ESCAPE_SEQ_3,
					ESCAPE_SEQ_4
	};

	int		fd;
	struct	termios originalTermios;

	void	enableRawMode(void);

public:
	keyboard();
	~keyboard();

	int	cursorRow, cursorColumn;

	int		readkey(int _fd);
	void	hideCursor(void);
	void	showCursor(void);
	void	moveCursor(int _x, int _y);
	void	disableRawMode(void);
	void	updateCursorValues(void);

};



/*
----------------------------------------------------------------------
|key			|escape|  seq[0]  |  seq[1]  |   seq2]   |  seq[3]   |
----------------------------------------------------------------------
|ESC			|  27  |          |          |           |           |
|TAB			|   9  |          |          |           |           |
|BK_SP  		| 127  |          |          |           |           |
|KB_ENTER		|  13  |          |          |           |           |
|NUM_ENTER		|  10  |          |          |           |           |
----------------------------------------------------------------------
|UP_ARROW		|  27  | 91 - '[' | 65 - 'A' |           |           |
|DOWN_ARROW		|  27  | 91 - '[' | 66 - 'B' |           |           |
|RIGHT_ARROW	|  27  | 91 - '[' | 67 - 'C' |           |           |
|LEFT_ARROW		|  27  | 91 - '[' | 68 - 'D' |           |           |
|F1				|  27  | 79 - 'O' | 80 - 'P' |           |           |
|F2				|  27  | 79 - 'O' | 81 - 'Q' |           |           |
|F3				|  27  | 79 - 'O' | 82 - 'R' |           |           |
|F4				|  27  | 79 - 'O' | 83 - 'S' |           |           |
----------------------------------------------------------------------
|HOME			|  27  | 91 - '[' | 49 - '1' | 126 - '~' |           |
|INSERT			|  27  | 91 - '[' | 50 - '2' | 126 - '~' |           |
|DELETE			|  27  | 91 - '[' | 51 - '3' | 126 - '~' |           |
|END			|  27  | 91 - '[' | 52 - '4' | 126 - '~' |           |
|PAGE_UP		|  27  | 91 - '[' | 53 - '5' | 126 - '~' |           |
|PAGE_DOWN		|  27  | 91 - '[' | 54 - '6' | 126 - '~' |           |
----------------------------------------------------------------------
|F9				|  27  | 91 - '[' | 50 - '2' | 48 - '0'  | 126 - '~' |
|F10			|  27  | 91 - '[' | 50 - '2' | 49 - '1'  | 126 - '~' |
|F11			|  27  | 91 - '[' | 50 - '2' | 51 - '3'  | 126 - '~' |
|F12			|  27  | 91 - '[' | 50 - '2' | 52 - '4'  | 126 - '~' |
|F5				|  27  | 91 - '[' | 49 - '1' | 53 - '5'  | 126 - '~' |
|F6				|  27  | 91 - '[' | 49 - '1' | 55 - '7'  | 126 - '~' |
|F7				|  27  | 91 - '[' | 49 - '1' | 56 - '8'  | 126 - '~' |
|F8				|  27  | 91 - '[' | 49 - '1' | 57 - '9'  | 126 - '~' |
----------------------------------------------------------------------
*/
