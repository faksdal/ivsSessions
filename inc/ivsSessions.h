/*
 * ivsSessions.h
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <termios.h>



////////////////////////////////////////////////////////////////////////////////
//////////// i v s S e s s i o n s  c l a s s  d e f i n i t i o n /////////////

class ivsSessions{
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// B A S I C S //////////////////////////////////
private:
	void errorMessage(const std::string _callerId, const std::string _message);


public:
	ivsSessions(std::string _inputFileName);
	~ivsSessions();

	int run(void);
///////////////////////////////// B A S I C S //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
///////////////////////// F I L E O P E R A T I O N S //////////////////////////
private:
	std::string		str_inputFileName;
	std::string		str_inputBuffer;

	std::ifstream	fs_inputFileStream;

	std::streampos	sp_inputFileSize;

	bool fileExists(const std::string _filename);
	void readFile(void);
///////////////////////// F I L E O P E R A T I O N S //////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// P A R S I N G /////////////////////////////////
private:
	// Different states used by the parser.
	// I'm using a state machine to parse the input file, and these enums
	// reflects the different states it can have.
	enum class State{	READY,
						NEW_LINE,
						FILE_FORMAT,
						HEADER,
						SESSION_TYPE,
						DATE,
						SESSION_CODE,
						DOY,
						TIME,
						DUR,
						STATIONS,
						SKED,
						CORR,
						STATUS,
						DBC_CODE,
						SUBM,
						DEL,
						HORIZONTAL_DIVIDER,
						FOOTER,
						CHECK_NEW_LINE,
						ADD_LIST_ITEM
	};

	// Working buffers, serves as intermediate placeholders for data, used to
	// add elements to the list. Represents corresponding data fields in the
	// list definition.
	std::string		str_sessionType;
	std::string		str_date;
	std::string		str_sessionCode;
	std::string		str_doy;
	std::string		str_time;
	std::string		str_dur;
	std::string		str_stations;
	std::string		str_sked;
	std::string		str_corr;
	std::string		str_status;
	std::string		str_dbcCode;
	std::string		str_subm;
	std::string		str_del;
	std::string		str_buffer;
	bool			b_visible;
	bool			b_highlighted;

	// pointer to the input buffer read from input file
	const char*		chr_ptr;

	// Holds the various states the parser can be in
	State	state;

	// Set to true if these are intensive sessions
	bool	b_intensiveFlag;

	// Master file format as reported in the input file
	std::string	str_fileFormat;

	// Resets the working buffers
	void	clearWorkingBuffers(void);
	void	parser(void);
	void	addListItem(void);

	// TODO: have a look at these, seee if they can be deleted
	//unsigned long		ul_inputBufferIndex;
	//bool	setIntensiveFlag(void);
//////////////////////////////// P A R S I N G /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//////////////////////////// S E S S I O N L I S T /////////////////////////////
private:
	class SessionList{
	public:
		std::string		str_sessionType;
		std::string		str_date;
		std::string		str_sessionCode;
		std::string		str_doy;
		std::string		str_time;
		std::string		str_dur;
		std::string		str_stations;
		std::string		str_sked;
		std::string		str_corr;
		std::string		str_status;
		std::string		str_dbcCode;
		std::string		str_subm;
		std::string		str_del;
		bool			b_visible;
		bool			b_highlighted;
	};

	// Holds the text for list headers
	std::string		str_header1, str_header2;

	// Dynamic list to hold all sessions
	std::vector<SessionList>	vl_sessionList;
//////////////////////////// S E S S I O N L I S T /////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
///////////////////////// T E R M I N A L  O U T P U T /////////////////////////
private:

	// Various parameters for screen and list boundaries
	class displayBoundaries{
	public:
		int	i_total_rows,
			i_total_columns,
			i_header1_row,
			i_header2_row,
			i_list_start_row,
			i_list_end_row;

		int	terminal_current_highlighted_row;

		unsigned long	terminal_current_highlighted_session,
						terminal_current_topmost_session;

	};

	// Hold terminal properties for restoring upon exit
	struct termios	originalTermios;

	// Color defs for terminal output, restricted to highlight and regular,
	class displayColors{
	public:
		std::string	str_headerColor;
	};

	displayColors		d_colors;
	displayBoundaries	d_bound;

	void	print(int _x, int _y, std::string _text);
	void	print(int _x, int _y, unsigned long _text);

	void	printHeaders(void);

	void	printSession(	short _row,
							unsigned long _sessionId,
							std::string _sessionColor);

	void	setupDisplay(void);
	void	saveTerminalState(void);
	void	restoreTerminalState(void);
	void	getTerminalSize(void);
	void	clearScreen(void);
	void	clearLines(int _startLine, int _numLines);

	void	redrawList(void);

///////////////////////// T E R M I N A L  O U T P U T /////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// K E Y B O A R D ////////////////////////////////
private:
	void	hideCursor(void) { std::cout << "\033[?25l" << std::flush; }
	void	showCursor(void) { std::cout << "\033[?25h" << std::flush; }
/////////////////////////////// K E Y B O A R D ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
};

/*
//////////// i v s S e s s i o n s  c l a s s  d e f i n i t i o n /////////////
////////////////////////////////////////////////////////////////////////////////


/////////////F I L T E R  C L A S S  D E F I N I T I O N////////////////////////
class Filter{
public:
	int			filterColumn, filterRow;
	bool		active;
	std::string	filterName, filterText, filterColor;
};
////////////////////////////////////////////////////////////////////////////////


///////////////// C L A S S  D E F I N I T I O N ///////////////////////////////
///////////////////// i v s S e s s i o n s ////////////////////////////////////
//
// Class definition, ivsSessions
//
class ivsSessions{



/////////////// K E Y B O A R D  I N P U T ///////////////////////////////////
//
// Private functions and variables related to keybard input
//
	keyboard		kb;

	void	processKeypress(bool& _quit);


/////////////// K E Y B O A R D  I N P U T ///////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////// T E R M I N A L  O U T P U T ////////////////////////////////////
//
// Private variables and functions related to terminal output
//


	std::string	itemListColor;

	displayBoundaries db;

	void	saveTerminalState(termios &_originalTermios);
	void	restoreTerminalState(const termios &_originalTermios);
	void	die(const char *s);
	void	moveCursor(int _column, int _row);




	void	printSessionList(void);
	void	printSession(short _row, unsigned long _sessionId, std::string _sessionColor);
	void	redraw(short _offset);
	void	updateSessionListDisplay(void);
////////////// T E R M I N A L  O U T P U T ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

///////////////////F I L T E R  D E F I N I T I O N S///////////////////////////


	std::vector<Filter>	filter;

	void	setupFilters(void);
	void	printFilters(void);
	void	nextFilter(void);
	void	addFilter(int _key);

///////////////////F I L T E R  D E F I N I T I O N S///////////////////////////
////////////////////////////////////////////////////////////////////////////////

};
///////////////// C L A S S  D E F I N I T I O N ///////////////////////////////
///////////////////// i v s S e s s i o n s ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

*/
