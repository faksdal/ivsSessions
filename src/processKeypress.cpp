/*
 * processKeypress.cpp
 *
 *  Created on: Nov 7, 2024
 *      Author: leijon
 */

#include <unistd.h>
#include "keymap.h"
#include "ivsSessions.h"



////////////////////////////////////////////////////////////////////////////////
//	Obtains and processes the user input
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processKeypress(bool& _quit)
{
	int key = readkey(STDIN_FILENO);

	switch(key){
		case TAB:			//nextFilter();
							break;
		case UP_ARROW:		//if(db.terminal_current_highlighted_row == db.terminal_list_start_row)
							//	break;
							//db.terminal_current_highlighted_row--;
							//db.terminal_current_highlighted_session--;
							//redraw(LIST_OFFSET_UP_ARROW);
							break;
		case DOWN_ARROW:	//if(	db.terminal_current_highlighted_row == db.terminal_list_end_row ||
							//	db.terminal_current_highlighted_row >= db.terminal_list_start_row + sessionList.size() - 1)	// See #pragma... at top
							//	break;

							//db.terminal_current_highlighted_row++;
							//db.terminal_current_highlighted_session++;
							//redraw(LIST_OFFSET_DOWN_ARROW);
							break;
		case ESC:			// ESC quits the program
							//kb.disableRawMode();
							_quit = true;
							break;
		default:			//kb.cursorColumn++;
							//itemListColor = "\033[40;00m";	// regular
							std::cout << (char)key << std::flush;
							//addFilter(key);
							break;
	}

}
