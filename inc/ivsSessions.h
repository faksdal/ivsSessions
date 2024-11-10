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

	// TODO: have a look at these, see if they can be deleted
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

	unsigned long	nextVisibleSession(unsigned long _startItem);
	unsigned long	previousVisibleSession(unsigned long _startItem);
	bool	findVisible(	unsigned long _startSession,
							unsigned long& _nextSession,
							int _direction);
	void	updateStatusLine(void);
	unsigned long visibleSessions(void);
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
			i_filter_row,
			i_list_start_row,
			i_list_end_row;

		int	i_current_highlighted_row;
	};

	class listTracking{
	public:
		unsigned long	ul_current_highlighted_session,
						ul_current_topmost_session,
						ul_current_highlighted_row;
	};

	// Color defs for terminal output, restricted to highlight and regular,
	class displayColors{
	public:
		std::string	str_default_color;
		std::string	str_header_color;
		std::string	str_filter_passive_color;
		std::string	str_filter_active_color;
		std::string	str_list_highlighted_color;
	};

	// Keeps track of the cursor location
	class cursorLocation{
	public:
		int	i_column, i_row;
	};

	enum ScrollState {	TOP,
						BOTTOM,
						MOVE_UP,
						MOVE_DOWN,
						SCROLL_UP,
						SCROLL_DOWN
	};

	displayColors		d_colors;
	displayBoundaries	d_bound;
	cursorLocation		c_where;
	listTracking		l_track;

	//ScrollState	scrollState;

	// Hold terminal properties for restoring upon exit
	struct termios	originalTermios;

	void	print(int _x, int _y, std::string _text);
	void	print(int _x, int _y, unsigned long _text);

	void	printHeaders(void);

	void	printSession(	short _row,
							unsigned long _sessionId,
							std::string _sessionColor);

	// Inline functions ////////////////////////////////////////////////////////
	void	setColor(const std::string _color)
				{ std::cout << _color << std::flush; }
	void	resetColor(void)
				{ setColor(d_colors.str_default_color); }
	void	moveCursor(int _column, int _row)
				{ std::cout << "\033[" << _row << ";" << _column << "H" << std::flush; }
	void	hideCursor(void)
				{ std::cout << "\033[?25l" << std::flush; }
	void	showCursor(void)
				{ std::cout << "\033[?25h" << std::flush; }
	////////////////////////////////////////////////////////////////////////////

	void	setupDisplay(void);
	void	saveTerminalState(void);
	void	restoreTerminalState(void);
	void	getTerminalSize(void);
	void	clearScreen(void);
	void	clearLines(int _startLine, int _numLines);
	void	redrawSessions(int _key);
	void	updateListTracking(	unsigned int _current_highlighted_session,
								unsigned int _current_topmost_session,
								unsigned int _current_highlighted_row);
	void	scrollSessionList(int _direction, int _numberOfLines);
	void	scrollSession(int _key);
	ivsSessions::ScrollState	getScrollState(int _key);
///////////////////////// T E R M I N A L  O U T P U T /////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// K E Y B O A R D ////////////////////////////////

private:
	void	disableRawmode(void);
	void	enableRawmode(void);
	int		readkey(int _fd);
	void	processKeypress(bool& _quit);
/////////////////////////////// K E Y B O A R D ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// F I L T E R S /////////////////////////////////
private:
	class Filter{
	public:
		int			i_filterColumn, i_filterRow, i_fieldLength;
		bool		b_active;
		std::string	str_filterName, str_filterText, str_filterColor;
	};

	std::vector<Filter>	vl_filter;

	void	setupFilters(void);
	void	addFilter(	int		_filterColumn,
						int		_filterRow,
						int		_fieldLength,
						bool	_active,
						std::string	_filterName,
						std::string	_filterText,
						std::string	_filterColor);
	void	setFocusActiveFilter(void);
	void	nextFilter(void);
	int		getActiveFilterIndex(void);

	//void	printFilters(void);
//////////////////////////////// F I L T E R S /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////



//////////// i v s S e s s i o n s  c l a s s  d e f i n i t i o n /////////////
////////////////////////////////////////////////////////////////////////////////
};

/*
	void	printSessionList(void);

	void	redraw(short _offset);
	void	updateSessionListDisplay(void);
*/




